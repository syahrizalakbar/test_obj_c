//
//  Email.h
//  TestObjC
//
//  Created by Syahrizal Akbar on 25/04/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface Email : NSObject

@property(nonatomic, copy, readonly) NSString *value;

-(id)initWithValue:(NSString *)value;

@end

NS_ASSUME_NONNULL_END
