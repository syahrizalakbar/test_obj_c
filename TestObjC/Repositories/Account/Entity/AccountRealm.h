//
//  AccountRealm.h
//  TestObjC
//
//  Created by Syahrizal Akbar on 27/04/24.
//

#import <Realm/Realm.h>

NS_ASSUME_NONNULL_BEGIN

@interface AccountRealm : RLMObject

@property NSString *_id;
@property NSString *name;
@property NSString *email;
@property NSString *phoneNumber;
@property NSString *birthDate;
@property NSString *address;

@end

@implementation AccountRealm

@end


NS_ASSUME_NONNULL_END
