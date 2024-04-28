//
//  IAccountRepository.h
//  TestObjC
//
//  Created by Syahrizal Akbar on 27/04/24.
//
#import "Account.h"

@protocol IAccountRepository <NSObject>

-(NSArray<Account*>*) getAllAccounts;
-(BOOL) createNewAccount:(Account*)newAccount;
-(BOOL) editAccount:(Account*)account;
-(BOOL) deleteAccount:(AccountID*)_id;

@end
