//
//  Account.m
//  TestObjC
//
//  Created by Syahrizal Akbar on 25/04/24.
//

#import "Account.h"

NS_ASSUME_NONNULL_BEGIN

@implementation Account

- (id)initWithValue:(nullable NSString *)accountId withName:(NSString *)name withEmail:(NSString *)email withPhone:(NSString *)phoneNumber withBirthDate:(NSString *)birthDate withAddress:(nullable NSString *)address {
    
    _accountId = accountId == nil ? [[AccountID alloc] init] : [[AccountID alloc] initWithValue:accountId];
    _name = [[Name alloc] initWithValue:name];
    _email = [[Email alloc] initWithValue:email];
    _phoneNumber = [[PhoneNumber alloc] initWithValue:phoneNumber];
    _birthDate = [[BirthDate alloc] initWithValue:birthDate];
    _address = address;
    
    return self;
}


@end

NS_ASSUME_NONNULL_END
