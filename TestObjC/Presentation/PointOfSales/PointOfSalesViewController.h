//
//  PointOfSalesViewController.h
//  TestObjC
//
//  Created by Syahrizal Akbar on 27/04/24.
//

#import <UIKit/UIKit.h>
#import "Tag.h"
#import "LineCart.h"

NS_ASSUME_NONNULL_BEGIN

@interface PointOfSalesViewController : UIViewController

@property(nonatomic, readonly) NSMutableArray<Tag*> *tags;
@property(nonatomic, readonly) NSMutableArray<LineCart*> *lineCart;

-(NSInteger) grandTotal;

@end

NS_ASSUME_NONNULL_END
