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
    BOOL hasPrefixPlus = [value hasPrefix:@"+"];
//    NSString *newValue;
    if (hasPrefixPlus) {
        value = [value stringByReplacingCharactersInRange:NSMakeRange(0,1) withString:@""];
    }
    
    // Check if the phone number contains only numeric characters
    NSCharacterSet *numericSet = [NSCharacterSet decimalDigitCharacterSet];
    NSCharacterSet *phoneSet = [NSCharacterSet characterSetWithCharactersInString:value];
    
    
    BOOL charactersAreValid = [numericSet isSupersetOfSet:phoneSet];
    if (!charactersAreValid) {
        @throw [NSException exceptionWithName:@"PhoneNumberException" reason:@"Invalid phone number" userInfo:nil];
    }
    
    if (hasPrefixPlus) {
        value = [NSString stringWithFormat:@"+%@", value];
    }
    
    NSUInteger length = value.length;
    BOOL isValidLength = length >= _minimumLength && length <= _maximumLength;
    if (!isValidLength) {
        @throw [NSException exceptionWithName:@"PhoneNumberException" reason:@"Invalid characters length" userInfo:nil];
    }
    
    _value = value;
    return self;
}

@end
