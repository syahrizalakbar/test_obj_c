//
//  ItemAccountCollectionViewCell.h
//  TestObjC
//
//  Created by Syahrizal Akbar on 27/04/24.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ItemAccountCollectionViewCell : UICollectionViewCell
@property (weak, nonatomic) IBOutlet UILabel *phone;
@property (weak, nonatomic) IBOutlet UILabel *name;
@property (weak, nonatomic) IBOutlet UIView *mainView;

- (void) setView:(NSString*)name phone:(NSString*)phone;

@end

NS_ASSUME_NONNULL_END
