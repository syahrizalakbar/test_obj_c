//
//  Name.m
//  TestObjC
//
//  Created by Syahrizal Akbar on 25/04/24.
//

#import "Name.h"

@implementation Name

static NSInteger _minimumLength = 5;

- (id)initWithValue:(NSString *)value {
    BOOL lengthIsValid = value.length >= _minimumLength;
    if (!lengthIsValid) {
        NSString *reason = [NSString stringWithFormat:@"Name less than %ld", (long)_minimumLength];
        @throw [NSException exceptionWithName:@"NameError" reason:reason userInfo:nil];
    }
    
    NSCharacterSet *allowedCharacterSet = [NSCharacterSet characterSetWithCharactersInString:@"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ "];
    BOOL isValid = [value rangeOfCharacterFromSet:[allowedCharacterSet invertedSet]].location == NSNotFound;
    if (!isValid) {
        NSString *reason = [NSString stringWithFormat:@"Name contains invalid character"];
        @throw [NSException exceptionWithName:@"NameError" reason:reason userInfo:nil];
    }
    
    
    _value = value;
    
    return self;
}

@end
