//
//  CartCollectionViewCell.h
//  TestObjC
//
//  Created by Syahrizal Akbar on 28/04/24.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
typedef void (^CompletionHandler)(NSInteger index);

@interface CartCollectionViewCell : UICollectionViewCell
@property (weak, nonatomic) IBOutlet UILabel *title;
@property (weak, nonatomic) IBOutlet UILabel *desc;
@property (weak, nonatomic) IBOutlet UILabel *total;
@property (nonatomic, copy) CompletionHandler completionHandler;
@property (nonatomic) NSInteger index;

-(void) setView:(NSString*)title index:(NSInteger)index desc:(NSString*)desc total:(NSString*)total;

@end

NS_ASSUME_NONNULL_END
