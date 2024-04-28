//
//  AccountID.m
//  TestObjC
//
//  Created by Syahrizal Akbar on 25/04/24.
//

#import "AccountID.h"
#import "Generator.h"

@implementation AccountID
    
-(id) init {
    _value = [Generator generateUUID];
    
    return self;
}

- (id)initWithValue:(NSString *)value {
    _value = value;
    
    return self;
}

@end
