//
//  IAccountService.h
//  TestObjC
//
//  Created by Syahrizal Akbar on 26/04/24.
//
#import <Foundation/Foundation.h>
#import "Account.h"

@protocol IAccountService

-(NSArray<Account*>*) getAllAccounts;
-(BOOL) createNewAccount:(Account*)newAccount;
-(BOOL) editAccount:(Account*)account;
-(BOOL) deleteAccount:(AccountID*)_id;

@end
