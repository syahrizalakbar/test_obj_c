//
//  NameTests.m
//  TestObjCTests
//
//  Created by Syahrizal Akbar on 25/04/24.
//

#import <XCTest/XCTest.h>
#import "Name.h"

@interface NameTests : XCTestCase

@end

@implementation NameTests


- (void)testNameShouldBeAtleast5Characters {
    Name *name = [Name alloc];
    
    XCTAssertThrows([name initWithValue:@"AAAA"], @"The length is too short");
    
}

- (void)testNameShouldOnlyContainAlphabet {
    Name *name = [Name alloc];
    
    XCTAssertThrows([name initWithValue:@"ASdad234"], @"Name contain invalid character");
}

-(void) testNameShouldBeValid {
    Name *name = [Name alloc];
    
    XCTAssertNoThrow([name initWithValue:@"AACAAA ASd"], @"Name is valid");
}


@end
