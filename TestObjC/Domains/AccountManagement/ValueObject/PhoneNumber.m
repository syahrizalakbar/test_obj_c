//
//  PhoneNumber.m
//  TestObjC
//
//  Created by Syahrizal Akbar on 25/04/24.
//

#import "PhoneNumber.h"

@implementation PhoneNumber

static NSInteger _minimumLength = 7;
static NSInteger _maximumLength = 15;

- (id)initWithValue:(nonnull NSString *)value {
    
    // Check if the phone number contains only numeric characters
    NSCharacterSet *numericSet = [NSCharacterSet decimalDigitCharacterSet];
    NSCharacterSet *phoneSet = [NSCharacterSet characterSetWithCharactersInString:value];
    
    BOOL hasPrefixPlus = [value hasPrefix:@"+"];
    if (hasPrefixPlus) {
        [value stringByReplacingCharactersInRange:NSMakeRange(0,0) withString:@""];
    }
    
    BOOL charactersAreValid = [numericSet isSupersetOfSet:phoneSet];
    if (!charactersAreValid) {
        @throw [NSException exceptionWithName:@"PhoneNumberException" reason:@"Invalid numbers" userInfo:nil];
    }
    
    if (hasPrefixPlus) {
        value = [NSString stringWithFormat:@"+%@", value];
    }
    
    NSUInteger length = value.length;
    BOOL isValidLength = length >= _minimumLength && length <= _maximumLength;
    if (!isValidLength) {
        @throw [NSException exceptionWithName:@"PhoneNumberException" reason:@"Invalid characters length" userInfo:nil];
    }
    
    return self;
}

@end
