//
//  NSMomentTests+Getters_Setters.m
//  NSMomentTests
//
//  Created by YannickL on 28/10/2013.
//
//

#import <XCTest/XCTest.h>

#define EXP_SHORTHAND
#import "Expecta.h"

#import "NSMoment.h"

@interface NSMomentTests_Getters_Setters : XCTestCase

@end

@implementation NSMomentTests_Getters_Setters

- (void)testGetters
{
    NSMoment *reference = [NSMoment momentWithArrayComponents:@[@2011, @9, @12, @6, @7, @8]];

    expect([reference year]).to.equal(2011);
    expect([reference month]).to.equal(9);
    expect([reference day]).to.equal(12);
    expect([reference hour]).to.equal(6);
    expect([reference minute]).to.equal(7);
    expect([reference second]).to.equal(8);
}

- (void)testSetters
{
    NSMoment *reference = [NSMoment now];
    reference.year      = 2011;
    reference.month     = 9;
    reference.day       = 12;
    reference.hour      = 6;
    reference.minute    = 7;
    reference.second    = 8;
    
    expect([reference year]).to.equal(2011);
    expect([reference month]).to.equal(9);
    expect([reference day]).to.equal(12);
    expect([reference hour]).to.equal(6);
    expect([reference minute]).to.equal(7);
    expect([reference second]).to.equal(8);
    
    reference        = [NSMoment momentWithDateAsString:@"20130531" format:@"yyyyMMdd"];
    reference.month  = 3;
    
    expect([reference month]).to.equal(3);
}

@end
