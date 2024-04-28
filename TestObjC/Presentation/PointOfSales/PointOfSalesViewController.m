//
//  PointOfSalesViewController.m
//  TestObjC
//
//  Created by Syahrizal Akbar on 27/04/24.
//

#import "PointOfSalesViewController.h"
#import "PointOfSales.h"
#import "TagViewCollectionViewCell.h"
#import "ProductCollectionViewCell.h"
#import "CartCollectionViewCell.h"

@interface PointOfSalesViewController ()<UICollectionViewDataSource, UICollectionViewDelegate, UICollectionViewDelegateFlowLayout>
@property (weak, nonatomic) IBOutlet UITextField *searchBar;
@property (weak, nonatomic) IBOutlet UIImageView *profilePict;
@property (weak, nonatomic) IBOutlet UIView *viewHeader;

@property (weak, nonatomic) IBOutlet UICollectionView *cvTag;
@property (weak, nonatomic) IBOutlet UICollectionView *cvCatalog;
@property (weak, nonatomic) IBOutlet UICollectionView *cvOrder;
@property (nonatomic, strong) NSIndexPath *selectedIndexPath;
@property (weak, nonatomic) IBOutlet UIView *openItem;
@property (weak, nonatomic) IBOutlet UIView *allTags;
@property (weak, nonatomic) IBOutlet UIView *promotionsTab;


@end

@implementation PointOfSalesViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [_profilePict.layer setCornerRadius:25];
    _pos = [[PointOfSales alloc] init];
    [_pos getTags];
    _cvTag.delegate = self;
    _cvCatalog.delegate = self;
    _cvOrder.delegate = self;
    _cvTag.dataSource = self;
    _cvCatalog.dataSource = self;
    _cvOrder.dataSource = self;
    
    
    /// Register Nib
    UINib *nib = [UINib nibWithNibName:@"TagViewCollectionViewCell" bundle:nil];
    [_cvTag registerNib:nib forCellWithReuseIdentifier:@"itemTag"];
    UINib *nib2 = [UINib nibWithNibName:@"ProductCollectionViewCell" bundle:nil];
    [_cvCatalog registerNib:nib2 forCellWithReuseIdentifier:@"itemProduct"];
    UINib *nib3 = [UINib nibWithNibName:@"CartCollectionViewCell" bundle:nil];
    [_cvOrder registerNib:nib3 forCellWithReuseIdentifier:@"itemCart"];
    
    
    [_openItem.layer setCornerRadius:10];
    [_allTags.layer setCornerRadius:10];
    [_promotionsTab.layer setCornerRadius:10];
    NSDictionary *attributes = @{
        NSForegroundColorAttributeName: [UIColor colorWithRed:0.9 green:0.9 blue:0.9 alpha:1.0] // Change the color as needed
    };
    NSAttributedString *attributedPlaceholder = [[NSAttributedString alloc] initWithString:@"Search" attributes:attributes];

    // Set the attributed placeholder text to the text field
    _searchBar.attributedPlaceholder = attributedPlaceholder;
    /// Setup icon search
    UIView *containerView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, 30, 20)];
    UIImageView *iconImageView = [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"ic_search"]];
    iconImageView.contentMode = UIViewContentModeScaleAspectFit;
    iconImageView.frame = CGRectMake(0, 0, 30, 20);
    [containerView addSubview:iconImageView];
    _searchBar.leftView = containerView;
    _searchBar.leftViewMode = UITextFieldViewModeAlways;
    
    
//    [_viewHeader.layer setBorderWidth:2];
    CALayer *bottomBorder = [CALayer layer];
    CGFloat borderWidth = 2.0; // Set the border width as needed
    bottomBorder.borderColor = [UIColor whiteColor].CGColor; // Set the border color
    bottomBorder.borderWidth = borderWidth;

    // Calculate the frame for the bottom border layer
    bottomBorder.frame = CGRectMake(0, CGRectGetHeight(_viewHeader.frame) - borderWidth, CGRectGetWidth(_viewHeader.frame), borderWidth);

    // Add the bottom border layer to the view's layer
    [_viewHeader.layer addSublayer:bottomBorder];
}

- (IBAction)exit:(id)sender {
    [self dismissViewControllerAnimated:true completion:nil];
}
//
- (NSInteger)collectionView:(UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section {
    
    if (collectionView == _cvTag) {
        return _pos.tags.count;
    } else if (collectionView == _cvCatalog) {
        return [_pos.tagActive serialDisplay].count;
    } else if (collectionView == _cvOrder) {
        return _pos.lineCart.count;
    }
    
    return 0;
}


- (__kindof UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath {
    if (collectionView == _cvCatalog) {
        ProductCollectionViewCell *cell = [collectionView dequeueReusableCellWithReuseIdentifier:@"itemProduct" forIndexPath:indexPath];
        
        Promotion *p = [_pos.tagActive serialDisplay][indexPath.row];
        
        NSInteger totalQty = 0;
        for (LineCart *l in _pos.lineCart) {
            if (l.indexDisplay1 == indexPath.row && l.promoType == p.type) {
                totalQty = l.qty;
                break;
            }
        }
        NSString *qtyString = [NSString stringWithFormat:@"%ld", (long)totalQty];
        
        switch (p.type) {
            case Combo:
                [cell setView:p.name desc:p.productCombo.firstObject.products.firstObject.name priceLeft:[NSString stringWithFormat:@"%@", p.productCombo.firstObject.products.firstObject.unitPrice] priceRight:[NSString stringWithFormat:@"%@", p.productCombo.lastObject.products.firstObject.unitPrice] qtyTotal:qtyString];
                break;
            case BOGO:
                [cell setView:p.name desc:p.productBogo.firstObject.product.name priceLeft:[NSString stringWithFormat:@"%@", p.productBogo.firstObject.product.unitPrice] priceRight:@"0" qtyTotal:qtyString];
                break;
            case Vc:
                [cell setView:p.name desc:p.vouchers.firstObject.name priceLeft:@"0" priceRight:@"0" qtyTotal:qtyString];
                break;
        }
        
        return cell;
    } else if (collectionView == _cvOrder) {
        CartCollectionViewCell *cell = [collectionView dequeueReusableCellWithReuseIdentifier:@"itemCart" forIndexPath:indexPath];
        LineCart *p = _pos.lineCart[indexPath.row];
        
        switch (p.type) {
            case Combo:
                [cell setView:p.productCombo.products.firstObject.name index:indexPath.row desc:p.productCombo.products.firstObject.name total:[NSString stringWithFormat:@"%ld", (long)(p.productCombo.price * p.qty)]];
                break;
            case BOGO:
                    [cell setView:p.productBogo.product.name index:indexPath.row desc:p.productBogo.product.name total:[NSString stringWithFormat:@"%ld", (long)([p.productBogo.product.unitPrice floatValue] * p.qty)]];
                break;
            case Vc:
                [cell setView:p.voucher.name index:indexPath.row desc:p.voucher.name total:[NSString stringWithFormat:@"%d", 0]];
                break;
        }
        
        cell.completionHandler = ^(NSInteger index) {
            [self->_pos removeChart:&index];
            [self->_cvOrder reloadData];
            [self->_cvCatalog reloadData];
            [self refreshGrandTotal];
        };
        
        return cell;
    }
    
    
    TagViewCollectionViewCell *cell = [collectionView dequeueReusableCellWithReuseIdentifier:@"itemTag" forIndexPath:indexPath];
    
    [cell setTag:_pos.tags[indexPath.row].name];
    return cell;
}

-(void) refreshGrandTotal {
    CGFloat total = [self->_pos grandTotal];
    [grandTotal setTitle:[NSString stringWithFormat:@"%.02f", total] forState:UIControlStateNormal];
}

- (NSInteger)numberOfSectionsInCollectionView:(UICollectionView *)collectionView {
    return 1;
}
//
- (CGSize)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout *)collectionViewLayout sizeForItemAtIndexPath:(NSIndexPath *)indexPath {
    if (collectionView == _cvCatalog) {
        CGFloat width = collectionView.frame.size.width;
        return CGSizeMake(width/3.2, width/3.2);
    }
    return CGSizeMake(240, 60);
}
//
- (void)collectionView:(UICollectionView *)collectionView didSelectItemAtIndexPath:(NSIndexPath *)indexPath {
    if (collectionView == _cvTag) {
        UICollectionViewCell *previousCell = [collectionView cellForItemAtIndexPath:self.selectedIndexPath];
        previousCell.backgroundColor = [UIColor darkGrayColor];

        // Set the background color of the selected cell
        UICollectionViewCell *selectedCell = [collectionView cellForItemAtIndexPath:indexPath];
        
        NSString *hexColor = @"#106E6E"; // Hexadecimal color code
        UIColor *color = [self colorFromHexString:hexColor];
        selectedCell.backgroundColor = color; // Set your desired background color
        [selectedCell.layer setCornerRadius:10];
        
        // Update the selectedIndexPath
        self.selectedIndexPath = indexPath;
        _pos.tagActive = _pos.tags[indexPath.row];
        [_cvCatalog reloadData];
    } else if (collectionView == _cvCatalog) {
        Promotion *p = [_pos.tagActive serialDisplay][indexPath.row];
        switch (p.type) {
            case Combo:
                [_pos addCartCombo:p.productCombo.firstObject index1:indexPath.row promoType:p.type];
                break;
            case BOGO:
                [_pos addCartBogo:p.productBogo.firstObject index1:indexPath.row promoType:p.type];
                break;
            case Vc:
                [_pos addCartVoucher:p.vouchers.firstObject index1:indexPath.row promoType:p.type];
                break;
        }
        [_cvCatalog reloadData];
        [_cvOrder reloadData];
        [self refreshGrandTotal];
    }
}

- (UIColor *)colorFromHexString:(NSString *)hexString {
    NSString *cleanString = [hexString stringByReplacingOccurrencesOfString:@"#" withString:@""];
    NSScanner *scanner = [NSScanner scannerWithString:cleanString];
    [scanner setCharactersToBeSkipped:[NSCharacterSet symbolCharacterSet]];
    unsigned int color;
    [scanner scanHexInt:&color];
    return [UIColor colorWithRed:((color & 0xFF0000) >> 16)/255.0 green:((color & 0x00FF00) >> 8)/255.0 blue:(color & 0x0000FF)/255.0 alpha:1.0];
}

@end
