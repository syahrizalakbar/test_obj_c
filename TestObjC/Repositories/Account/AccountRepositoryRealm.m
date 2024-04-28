//
//  AccountRepositoryRealm.m
//  TestObjC
//
//  Created by Syahrizal Akbar on 27/04/24.
//

#import "AccountRepositoryRealm.h"
#import "AccountRealm.h"
#import <Realm/Realm.h>

@implementation AccountRepositoryRealm

-(id) init {
    _rdb = [RLMRealm defaultRealm];
    
    return self;
}

- (BOOL)createNewAccount:(Account *)newAccount { 
    [_rdb transactionWithBlock:^{
        [AccountRealm createInRealm:_rdb withValue:@{
            @"_id": newAccount.accountId.value,
            @"name": newAccount.name.value,
            @"email": newAccount.email.value,
            @"phoneNumber": newAccount.phoneNumber.value,
            @"birthDate": newAccount.birthDate.value,
            @"address": newAccount.address,
        }];
    }];
    return true;
}

- (BOOL)deleteAccount:(AccountID *)_id { 
    AccountRealm *object = [[AccountRealm objectsWhere:@"_id == %@", _id.value] firstObject];
    [_rdb transactionWithBlock:^{
        [_rdb deleteObject:object];
    }];
    return true;
}

- (BOOL)editAccount:(Account *)account { 
    AccountRealm *object = [[AccountRealm objectsWhere:@"_id == %@", account.accountId.value] firstObject];
    [_rdb transactionWithBlock:^{
        object.name = account.name.value;
        object.email = account.email.value;
        object.phoneNumber = account.phoneNumber.value;
        object.birthDate = account.birthDate.value;
        object.address = account.address;
    }];
    return true;
}

- (NSArray<Account *> *)getAllAccounts { 
    NSLog(@"Alhamdulillah");
    RLMResults<AccountRealm *> *accounts = [AccountRealm allObjectsInRealm:_rdb];
    NSMutableArray<Account *> *datas = [[NSMutableArray alloc] init];
    for (AccountRealm *account in accounts) {
        Account *mapped = [[Account alloc] initWithValue:account._id withName:account.name withEmail:account.email withPhone:account.phoneNumber withBirthDate:account.birthDate withAddress:account.address];
        [datas addObject:mapped];
    }
    
    return [datas copy];
}

@end
