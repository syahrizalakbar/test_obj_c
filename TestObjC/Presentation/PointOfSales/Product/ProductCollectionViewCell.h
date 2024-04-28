//
//  ProductCollectionViewCell.h
//  TestObjC
//
//  Created by Syahrizal Akbar on 28/04/24.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ProductCollectionViewCell : UICollectionViewCell
@property (weak, nonatomic) IBOutlet UILabel *name;
@property (weak, nonatomic) IBOutlet UILabel *desc;
@property (weak, nonatomic) IBOutlet UILabel *priceLeft;
@property (weak, nonatomic) IBOutlet UILabel *priceRight;
@property (weak, nonatomic) IBOutlet UILabel *qtyTotal;
@property (weak, nonatomic) IBOutlet UIView *counter;

-(void) setView:(NSString*)name desc:(NSString*)desc priceLeft:(NSString*)priceLeft priceRight:(NSString*)priceRight qtyTotal:(NSString*)qtyTotal;

@end

NS_ASSUME_NONNULL_END
