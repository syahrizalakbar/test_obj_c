//
//  AccountRepositoryRealm.h
//  TestObjC
//
//  Created by Syahrizal Akbar on 27/04/24.
//

#import <Foundation/Foundation.h>
#import "IAccountRepository.h"
#import <Realm/Realm.h>

NS_ASSUME_NONNULL_BEGIN

@interface AccountRepositoryRealm : NSObject<IAccountRepository> {
    RLMRealm *_rdb;
}

@end

NS_ASSUME_NONNULL_END
