//
//  Email.m
//  TestObjC
//
//  Created by Syahrizal Akbar on 25/04/24.
//

#import "Email.h"

@implementation Email

- (id)initWithValue:(nonnull NSString *)value {
    NSString *emailRegex = @"[A-Z0-9a-z._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,64}";
    NSPredicate *emailTest = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", emailRegex];
    BOOL emailIsValid = [emailTest evaluateWithObject:value];
    if (!emailIsValid) {
        @throw [NSException exceptionWithName:@"EmailException" reason:@"Email format is invalid" userInfo:nil];
    }
    
    _value = value;
    
    return self;
}

@end
