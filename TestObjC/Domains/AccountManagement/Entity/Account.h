//
//  Account.h
//  TestObjC
//
//  Created by Syahrizal Akbar on 25/04/24.
//

#import "AggregateRoot.h"
#import "AccountID.h"
#import "Name.h"
#import "Email.h"
#import "PhoneNumber.h"
#import "BirthDate.h"

NS_ASSUME_NONNULL_BEGIN

@interface Account : AggregateRoot {
    AccountID *_id;
    Name *_name;
    Email *_email;
    PhoneNumber *_phoneNumber;
    BirthDate *_birthDate;
    NSString *_address;
}

-(id) initWithValue:(nullable NSString *)accountId withName:(NSString *)name withEmail:(NSString *)email withPhone:(NSString *)phoneNumber withBirthDate:(NSString *)birthDate withAddress:(nullable NSString *)address;


@end

NS_ASSUME_NONNULL_END
