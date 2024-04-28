//
//  UserManagementViewController.h
//  TestObjC
//
//  Created by Syahrizal Akbar on 27/04/24.
//

#import <UIKit/UIKit.h>
#import "AccountManagement.h"

NS_ASSUME_NONNULL_BEGIN

@interface UserManagementViewController : UIViewController {
    AccountManagement *_accountManagement;
}

@property (weak, nonatomic) IBOutlet UICollectionView *accountCollectionView;
@property (weak, nonatomic) IBOutlet UIView *sideView;
@property (weak, nonatomic) IBOutlet UITextField *search;


@property (weak, nonatomic) IBOutlet UITextField *phoneNumber;
@property (weak, nonatomic) IBOutlet UITextField *email;
@property (weak, nonatomic) IBOutlet UITextField *name;
@property (weak, nonatomic) IBOutlet UITextField *birthdate;
@property (weak, nonatomic) IBOutlet UITextField *address;


@end

NS_ASSUME_NONNULL_END
