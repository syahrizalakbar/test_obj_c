//
//  BirthDateTests.m
//  TestObjCTests
//
//  Created by Syahrizal Akbar on 25/04/24.
//

#import <XCTest/XCTest.h>
#import "BirthDate.h"

@interface BirthDateTests : XCTestCase

@end

@implementation BirthDateTests

- (void)testInvalidDateTooOld {
    BirthDate *birthDate = [BirthDate alloc];
    
    NSString *formattedDate;
    
    @autoreleasepool {
        NSDate *dateNow = [NSDate date];
        NSCalendar *calendar = [NSCalendar currentCalendar];
        NSDateComponents *dateComponents = [[NSDateComponents alloc] init];
        [dateComponents setYear:[BirthDate maximumYearsOld]*-1];
        
        NSDate *invalidDate = [calendar dateByAddingComponents:dateComponents toDate:dateNow options:0];
        
        NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
        [dateFormatter setDateFormat:[BirthDate dateFormat]];
        
        formattedDate = [dateFormatter stringFromDate:invalidDate];
    }
    
    XCTAssertThrows([birthDate initWithValue:formattedDate], @"BirthDate is nonsense too old");
}

- (void)testInvalidDateTooYoung {
    BirthDate *birthDate = [BirthDate alloc];
    
    NSString *formattedDate;
    
    @autoreleasepool {
        NSDate *dateNow = [NSDate date];
        NSCalendar *calendar = [NSCalendar currentCalendar];
        NSDateComponents *dateComponents = [[NSDateComponents alloc] init];
        [dateComponents setYear:([BirthDate minimumYearsOld]-1)*-1];
        
        // Set invalid years
        NSDate *invalidDate = [calendar dateByAddingComponents:dateComponents toDate:dateNow options:0];
        
        NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
        [dateFormatter setDateFormat:[BirthDate dateFormat]];
        
        formattedDate = [dateFormatter stringFromDate:invalidDate];
    }
    
    
    XCTAssertThrows([birthDate initWithValue:formattedDate], @"BirthDate is nonsense too young");
}

- (void)testInvalidDateNotCorrectDate {
    BirthDate *birthDate = [BirthDate alloc];
    
    
    XCTAssertThrows([birthDate initWithValue:@"32-02-2000"], @"BirthDate is nonsense too old");
}

- (void)testValidDate {
    BirthDate *birthDate = [BirthDate alloc];
    
    
    XCTAssertNoThrow([birthDate initWithValue:@"22-12-2000"], @"BirthDate is valid");
}

@end
