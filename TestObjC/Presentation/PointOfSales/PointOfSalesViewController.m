//
//  PointOfSalesViewController.m
//  TestObjC
//
//  Created by Syahrizal Akbar on 27/04/24.
//

#import "PointOfSalesViewController.h"

@interface PointOfSalesViewController ()

@end

@implementation PointOfSalesViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (NSInteger)grandTotal {
    CGFloat total = 0;
    for (NSInteger i = 0; i < _lineCart.count; i++) {
        total += [_lineCart[i] calculateTotalPrice];
    }
    return total;
}

- (IBAction)exit:(id)sender {
    [self dismissViewControllerAnimated:true completion:nil];
}

@end
