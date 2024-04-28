//
//  AccountManagement.h
//  TestObjC
//
//  Created by Syahrizal Akbar on 26/04/24.
//

#import <Foundation/Foundation.h>
#import "Account.h"
#import "IAccountService.h"

NS_ASSUME_NONNULL_BEGIN

@interface AccountManagement : NSObject {
    IAccountService *_accountService;
}

@property(nonatomic, copy, readonly) NSMutableArray<Account*> *accounts;

-(void) getAllAcounts;
-(BOOL) createNewAccount:(Account*)newAccount;
-(BOOL) editAccount:(Account*)account;
-(BOOL) deleteAccount:(AccountID*)_id;

@end

NS_ASSUME_NONNULL_END
