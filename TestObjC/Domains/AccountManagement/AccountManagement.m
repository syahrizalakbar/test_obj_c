//
//  AccountManagement.m
//  TestObjC
//
//  Created by Syahrizal Akbar on 26/04/24.
//


#import "AccountManagement.h"
#import "AccountService.h"

NS_ASSUME_NONNULL_BEGIN

@implementation AccountManagement

- (id) init {
    _accountService = [[AccountService alloc] init];
    return self;
}

- (void)getAllAcounts {
    _accounts = [[_accountService getAllAccounts] mutableCopy];
}

- (BOOL)createNewAccount:(nonnull Account *)newAccount {
    BOOL isSuccess = [_accountService createNewAccount:newAccount];
    [self getAllAcounts];
    return isSuccess;
}

- (BOOL)deleteAccount:(nonnull AccountID *)_id {
    BOOL isSuccess = [_accountService deleteAccount:_id];
    [self getAllAcounts];
    return isSuccess;
}

- (BOOL)editAccount:(nonnull Account *)account {
    BOOL isSuccess = [_accountService editAccount:account];
    [self getAllAcounts];
    return isSuccess;
}

@end

NS_ASSUME_NONNULL_END
