//
//  PointOfSalesViewController.h
//  TestObjC
//
//  Created by Syahrizal Akbar on 27/04/24.
//

#import <UIKit/UIKit.h>
#import "PointOfSales.h"

NS_ASSUME_NONNULL_BEGIN

@interface PointOfSalesViewController : UIViewController {
    PointOfSales *_pos;
    __weak IBOutlet UIButton *grandTotal;
}

@end

NS_ASSUME_NONNULL_END
