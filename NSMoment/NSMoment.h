/*
 * NSMoment.h
 *
 * Copyright 2013 Yannick Loriot.
 * http://yannickloriot.com
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 */

#import <Foundation/Foundation.h>

static NSString * const NSMomentIso8601Format = @"yyyy-MM-dd'T'HH:mm:ssZ";

/**
 * `NSMoment` is a library which provides an high abstraction level for parsing,
 * validating, manipulating, and formatting the dates in Objective-C.
 *
 * Its API is inspired by the well know [moment.js](http://momentjs.com/)
 * library and its core is build upon the `Foundation Framework` components
 * (`NSDate`, `NSDateFormatter`,etc.).
 */
@interface NSMoment : NSObject

#pragma mark Creating and Initializing Moment Objects
/** @name Creating and Initializing Moment Objects */

/**
 * @abstract Creates and returns a moment which is set to the current date.
 * @version 0.1.0
 */
+ (id)now;

/**
 * @abstract Initializes a moment using a given date.
 * @param date a date.
 * @version 0.1.0
 */
- (id)initWithDate:(NSDate *)date;

/**
 * @abstract Creates and returns a moment using a given date.
 * @param date a date.
 * @see initWithDate:
 * @version 0.1.0
 */
+ (id)momentWithDate:(NSDate *)date;

/**
 * @abstract Initializes a moment with an array of numbers that mirror the 
 * following components ['year', 'month', 'day', 'hour', 'minute', 'second'].
 * @param dateAsArray An array which represent the date components.
 * @discussion The moment will create a date in the current timezone.
 * @version 0.1.0
 */
- (id)initWithArrayComponents:(NSArray *)dateAsArray;

/**
 * @abstract Creates and returns a moment with an array of numbers that mirror
 * the following components ['year', 'month', 'day', 'hour', 'minute', 'second'].
 * @param dateAsArray An array which represent the date components.
 * @discussion The moment will create a date in the current timezone.
 * @version 0.1.0
 */
+ (id)momentWithArrayComponents:(NSArray *)dateAsArray;

/**
 * @abstract Initializes a moment using the date representation of a given
 * string interpreted.
 * @param dateAsString The date string to parse.
 * @discussion The initializer uses the `NSDataDetector` to interpret the date
 * format.
 * @version 0.1.0
 */
- (id)initWithDateAsString:(NSString *)dateAsString;

/**
 * @abstract Creates and returns a moment using the date representation of a 
 * given string.
 * @param dateAsString The date string to parse.
 * @discussion The initializer uses the `NSDataDetector` to interpret the date
 * format.
 * @see initWithDateAsString:
 * @version 0.1.0
 */
+ (id)momentWithDateAsString:(NSString *)dateAsString;

/**
 * @abstract Initialize a moment using the date representation of a given string
 * interpreted and using a given date format.
 * @param dateAsString The date string to parse.
 * @param dateFormat The date format string used by the receiver.
 * @version 0.1.0
 */
- (id)initWithDateAsString:(NSString *)dateAsString format:(NSString *)dateFormat;

/**
 * @abstract Creates and returns a moment using the date representation of a 
 * given string interpreted and using a given date format.
 * @param dateAsString The date string to parse.
 * @param dateFormat The date format string used by the receiver.
 * @see initWithDateAsString:format:
 * @version 0.1.0
 */
+ (id)momentWithDateAsString:(NSString *)dateAsString format:(NSString *)dateFormat;

/**
 * @abstract Initialize a moment using the date representation of a given string
 * interpreted, a given date format, and a given locale identifier.
 * @param dateAsString The date string to parse.
 * @param dateFormat The date format string used by the receiver.
 * @param localeIdentifier The identifier for the new locale for the receiver.
 */
- (id)initWithDateAsString:(NSString *)dateAsString format:(NSString *)dateFormat localeIdentifier:(NSString *)localeIdentifier;

/**
 * @abstract Creates and returns a moment using the date representation of a
 * given string interpreted, a given date format, and a given locale identifier.
 * @param dateAsString The date string to parse.
 * @param dateFormat The date format string used by the receiver.
 * @param localeIdentifier The identifier for the new locale for the receiver.
 * @see initWithDateAsString:format:localeIdentifier:
 * @version 0.1.0
 */
+ (id)momentWithDateAsString:(NSString *)dateAsString format:(NSString *)dateFormat localeIdentifier:(NSString *)localeIdentifier;

#pragma mark Configuring Moments
/** @name Configuring Moments */

/**
 * @abstract Returns the proxy for the receiver.
 * @return The appearance proxy for the receiver.
 * @discussion The proxy is useful to configuring the `NSMoment` in a global way.
 * @version 0.1.0
 */
+ (instancetype)proxy;

/**
 * @abstract The calendar that will be used for the date calculations.
 * @discussion The default value is set to the current calendar.
 * @version 0.1.0
 */
@property (atomic, strong) NSCalendar *calendar;

/**
 * @abstract The local that will be used to display the dates.
 * @discussion The default value is set to the current locale.
 * @version 0.1.0
 */
@property (atomic, strong) NSLocale *locale;

#pragma mark Representing Moments as Strings
/** @name Representing Moments as Strings */

/**
 * @abstract Returns a string representation of the moment formatted using the 
 * `ISO-8601` format.
 * @return A string representation of the moment formatted using the `ISO-8601`
 * format.
 * @version 0.1.0
 */
- (NSString *)format;

/**
 * @abstract Returns a string representation of the moment formatted using a
 * given date format.
 * @param dateFormat The date format for the receiver. See [Date Formatting Guide](https://developer.apple.com/library/ios/documentation/Cocoa/Conceptual/DataFormatting/Articles/dfDateFormatting10_4.html#//apple_ref/doc/uid/TP40002369-SW1)
 * for a list of the conversion specifiers permitted in date format strings.
 * @return A string representation of the moment formatted using a given date
 * format.
 * @discussion The breakdown of which string is displayed for each format 
 * tokens is outlined in the table below:
 *
 * Format String         | Output String
 * --------------------- | --------------
 * M/d/y                 | 11/4/2012
 * MM/dd/yy              | 11/04/12
 * MMM d, ''yy           | Nov 4, '12
 * MMMM                  | November
 * E                     | Sun
 * EEEE                  | Sunday
 * 'Week' w 'of 52'      | Week 45 of 52
 * 'Day' D 'of 365'      | Day 309 of 365
 * QQQ                   | Q4
 * QQQQ                  | 4th quarter
 * m 'minutes past' h    | 9 minutes past 8
 * h:mm a                | 8:09 PM
 * HH:mm:ss's'           | 20:09:00s
 * HH:mm:ss:SS           | 20:09:00:00
 * h:mm a zz             | 8:09 PM CST
 * h:mm a zzzz           | 8:09 PM Central Standard Time
 * yyyy-MM-dd HH:mm:ss Z | 2012-11-04 20:09:00 -0600
 *
 * @version 0.1.0
 */
- (NSString *)format:(NSString *)dateFormat;

#pragma mark Validating Moments
/** @name Validating Moments */

/**
 * @abstract Returns true whether the current moment is valid.
 * @return `true` whether the current moment is valid.
 * @version 0.1.0
 */
- (BOOL)isValid;

#pragma mark Converting Moments
/** @name Working with Moments */

/**
 * Returns the `NSDate` corresponding to the current moment.
 * @return the `NSDate` corresponding to the current moment.
 * @version 0.1.0
 */
- (NSDate *)date;

#pragma mark Comparing Moments
/** @name Comparing Moments */

/**
 * @abstract Returns a Boolean value that indicates whether a given object
 * is an `NSMoment` object and exactly equal the receiver.
 * @param anotherMoment The moment to compare with the receiver.
 * @return YES if the anotherMoment is an `NSMoment` object and is exactly
 * equal to the receiver, otherwise NO.
 * @version 0.1.0
 */
- (BOOL)isEqualToMoment:(NSMoment *)anotherMoment;

#pragma mark Working with Relative Time
/** @name Working with Relative Times */

/**
 * @abstract Returns a suffixed string representing the relative time using
 * the locale of the moment.
 * @return A suffixed string with the representing time using the locale of
 * the moment.
 * @see fromNowWithSuffix:
 * @version 0.1.0
 */
- (NSString *)fromNow;

/**
 * @abstract Returns a string representing the relative time using the 
 * locale of the moment and suffixed if necessary.
 * @param suffixed Tells whether the relative time needs to be suffixed. E.g.
 * a relative suffixed time looks that `4 years ago` whereas a relative 
 * unsuffixed time looks like this `4 years`.
 * @return a string representing the relative time using the locale of the
 * moment and suffixed if necessary.
 * @discussion The breakdown of which string is displayed for each length
 * of time is outlined in the table below:
 *
 * Range                       | Key | Sample Output
 * --------------------------- | --- | -------------
 * 0 to 45 seconds             | s   | a few seconds ago
 * 45 to 90 seconds            | m   | a minute ago
 * 90 seconds to 45 minutes    | mm  | 2 minutes ago ... 45 minutes ago
 * 45 to 90 minutes            | h   | an hour ago
 * 90 minutes to 22 hours      | hh  | 2 hours ago ... 22 hours ago
 * 22 to 36 hours              | d   | a day ago
 * 36 hours to 25 days         | dd  | 2 days ago ... 25 days ago
 * 25 to 45 days               | M   | a month ago
 * 45 to 345 days              | MM  | 2 months ago ... 11 months ago
 * 345 to 547 days (1.5 years) | y   | a year ago
 * 548 days+                   | yy  | 2 years ago ... 20 years ago
 *
 * @version 0.1.0
 */
- (NSString *)fromNowWithSuffix:(BOOL)suffixed;

#pragma mark Manipulating Moments
/** @name Manipulating Moments */

/**
 * @abstract Mutates and returns the original moment by adding time. To add 
 * time, pass the key of what time you want to add, and the amount you want to add.
 * @param amount The amount of time you want to add.
 * @param key The key of what time you want to add.
 * @return The current moment with the amount of time added for a fluent interface
 * pattern.
 * @discussion There are some shorthand keys as well if you're into that whole
 * brevity thing:
 *
 * Key          | Shorthand | NSCalendarUnit Correspondence
 * ------------ | --------- | -----------------------------
 * years        | y         | `NSCalendarUnitYear`
 * months       | M         | `NSCalendarUnitMonth`
 * weeks        | w         | `NSCalendarUnitWeekOfMonth`
 * days         | d         | `NSCalendarUnitDay`
 * hours        | h         | `NSCalendarUnitHour`
 * minutes      | m         | `NSCalendarUnitMinute`
 * seconds      | s         | `NSCalendarUnitSecond`
 *
 * @version 0.1.0
 */
- (NSMoment *)addAmountOfTime:(NSInteger)amount forUnitKey:(NSString *)key;

/**
 * @abstract Mutates and returns the original moment by adding time. To add
 * time, pass the calendar unit of what time you want to add, and the amount
 * you want to add.
 * @param amount The amount of time you want to add.
 * @param unit The calendar unit of what time you want to add.
 * @return The current moment with the amount of time added for a fluent interface
 * pattern.
 * @version 0.1.0
 */
- (NSMoment *)addAmountOfTime:(NSInteger)amount forCalendarUnit:(NSCalendarUnit)unit;

/**
 * @abstract Mutates and returns the original moment by adding a time duration.
 * @param duration A time interval to add.
 * @return The current moment with the time duration added for a fluent interface
 * pattern.
 * @version 0.1.0
 */
- (NSMoment *)addDuration:(NSTimeInterval)duration;

#pragma mark Getting/Setting Moment Components
/** @name Getting/Setting Moment Components */

/**
 * @abstract Gets or sets the seconds.
 * @discussion Accepts numbers from 0 to 59. If the range is exceeded, it will bubble
 * up to the minutes.
 * @version 0.1.0
 */
@property (nonatomic, assign) NSUInteger second;

/**
 * @abstract Gets or sets the minutes.
 * @discussion Accepts numbers from 0 to 59. If the range is exceeded, it will bubble
 * up to the hours.
 * @version 0.1.0
 */
@property (nonatomic, assign) NSUInteger minute;

/**
 * @abstract Gets or sets the hour.
 * @discussion Accepts numbers from 0 to 23. If the range is exceeded, it will bubble 
 * up to the day.
 * @version 0.1.0
 */
@property (nonatomic, assign) NSUInteger hour;

/**
 * @abstract Gets or sets the hour.
 * @discussion Accepts numbers from 0 to 23. If the range is exceeded, it will bubble
 * up to the day.
 * @version 0.1.0
 */
@property (nonatomic, assign) NSUInteger day;

/**
 * @abstract Gets or sets the month.
 * @discussion Accepts numbers from 0 to 11. If the range is exceeded, it will bubble
 * up to the year.
 * @version 0.1.0
 */
@property (nonatomic, assign) NSUInteger month;

/**
 * @abstract Gets or sets the year.
 * @version 0.1.0
 */
@property (nonatomic, assign) NSUInteger year;

@end
