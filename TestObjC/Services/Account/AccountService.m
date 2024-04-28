//
//  AccountService.m
//  TestObjC
//
//  Created by Syahrizal Akbar on 27/04/24.
//

#import "AccountService.h"
#import "AccountRepositoryRealm.h"

@implementation AccountService

-(id) init {
    _accountRepository = [[AccountRepositoryRealm alloc] init];
    return self;
}

- (BOOL)createNewAccount:(Account *)newAccount { 
    return [_accountRepository createNewAccount:newAccount];
}

- (BOOL)deleteAccount:(AccountID *)_id { 
    return [_accountRepository deleteAccount:_id];
}

- (BOOL)editAccount:(Account *)account { 
    return [_accountRepository editAccount:account];
}

- (NSArray<Account *> *)getAllAccounts {
    return [_accountRepository getAllAccounts];
}

@end
