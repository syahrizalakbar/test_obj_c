//
//  BirthDate.m
//  TestObjC
//
//  Created by Syahrizal Akbar on 25/04/24.
//

#import "BirthDate.h"

@implementation BirthDate

static NSString *_dateFormat = @"dd-MM-yyyy";
static NSInteger _minimumYearsOld = 5;
static NSInteger _maximumYearsOld = 100;

+ (NSString *) dateFormat { return _dateFormat; }
+ (NSInteger) minimumYearsOld { return _minimumYearsOld; }
+ (NSInteger) maximumYearsOld { return _maximumYearsOld; }

- (nonnull id)initWithValue:(nonnull NSString *)value {
    NSDate *dateNow = [NSDate date];
    NSCalendar *calendar = [NSCalendar currentCalendar];
    NSDateComponents *dateComponents = [[NSDateComponents alloc] init];
    NSDate *dateValue;
    
    // Parse value into NSDate
    NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
    [dateFormatter setDateFormat:_dateFormat];
    dateValue = [dateFormatter dateFromString:value];
    
    BOOL isValidDate = dateValue != nil;
    if (!isValidDate) {
        @throw [NSException exceptionWithName:@"BirthDateException" reason:@"BirthDate is Invalid" userInfo:nil];
    }
    
    // Validate too young
    [dateComponents setYear:_minimumYearsOld*-1];
    NSDate *tooYoungDate = [calendar dateByAddingComponents:dateComponents toDate:dateNow options:0];
    
    NSComparisonResult result1 = [dateValue compare:tooYoungDate];
    BOOL isTooYoung = result1 == NSOrderedDescending;
    if (isTooYoung) {
        @throw [NSException exceptionWithName:@"BirthDateException" reason:@"BirthDate is Too Young" userInfo:nil];
    }
    
    // Validate too old
    [dateComponents setYear:_maximumYearsOld*-1];
    NSDate *tooOldDate = [calendar dateByAddingComponents:dateComponents toDate:dateNow options:0];
    NSComparisonResult result2 = [tooOldDate compare:dateValue];
    BOOL isTooOld = result2 == NSOrderedDescending;
    if (isTooOld) {
        @throw [NSException exceptionWithName:@"BirthDateException" reason:@"BirthDate is Too Old" userInfo:nil];
    }
    _value = value;
    return self;
}

@end
