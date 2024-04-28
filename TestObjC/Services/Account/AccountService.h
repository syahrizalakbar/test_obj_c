//
//  AccountService.h
//  TestObjC
//
//  Created by Syahrizal Akbar on 27/04/24.
//

#import <Foundation/Foundation.h>
#import "IAccountRepository.h"
#import "IAccountService.h"

NS_ASSUME_NONNULL_BEGIN

@interface AccountService : NSObject<IAccountService> {
    id<IAccountRepository> _accountRepository;
}

@end

NS_ASSUME_NONNULL_END
