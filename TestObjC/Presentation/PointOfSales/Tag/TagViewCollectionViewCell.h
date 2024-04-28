//
//  TagViewCollectionViewCell.h
//  TestObjC
//
//  Created by Syahrizal Akbar on 28/04/24.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TagViewCollectionViewCell : UICollectionViewCell
@property (weak, nonatomic) IBOutlet UILabel *tagName;
@property (weak, nonatomic) IBOutlet UIView *masterView;

-(void) setTag:(NSString*)tag;

@end

NS_ASSUME_NONNULL_END
