//
//  WDArithmeticOCManager.m
//  WDArithmetic
//
//  Created by 伟东 on 2020/12/23.
//

#import "WDArithmeticOCManager.h"

@implementation WDArithmeticOCManager

//----------------------------------------------------
//两个很长的数字字符串，计算两个的和(数学加法可能会存在溢出的问题)
- (void)addLongString {
    NSArray *array = [self addNum:@"1234567890987654321" b:@"9991234567899999999"];
    NSMutableString *str = [[NSMutableString alloc] init];
    for (int i = 0; i<array.count; i++) {
        if (i ==0 && [array.firstObject intValue] == 0) {
            continue;
        }
        [str appendString:[[array objectAtIndex:i] stringValue]];
    }
    NSLog(@"%@",str);
}

- (NSArray *)addNum:(NSString *)a b:(NSString *)b {
    
    // 对数字字符串做格式处理 不足位补0
    NSArray *prepare = [self prepare:a b:b];
    
    a = prepare.firstObject;
    b = prepare.lastObject;
    NSLog(@"%@",a);
    NSLog(@"%@",b);

    NSMutableArray *temp = [NSMutableArray array];
    int num = 0;
    int num1 = 0;
    int num2 = 0;
    int len = (int)a.length;
    int j = 1;
    for (int j = 0; j<len+1; j++) {
        [temp addObject:@(0)];
    }
    
    for (int i = len - 1; i>=0; i--) {
        NSRange range = NSMakeRange(i, 1);
        num1 = [a substringWithRange:range].intValue;
        num2 = [b substringWithRange:range].intValue;
        
        num = num1 + num2;
        int count = (int)temp.count;
        num = num + [[temp objectAtIndex:count-j] intValue];
        
        if (count-j-1>=0) {
            [temp replaceObjectAtIndex:count-j  withObject:@(num%10)];
            [temp replaceObjectAtIndex:count-j-1 withObject:@(num/10)];
        }
        j++;
    }
    return temp;
}


- (NSArray *)prepare:(NSString *)a b:(NSString *)b {
    NSMutableArray *temp = [NSMutableArray array];
    if (a.length > b.length) {
        b = [self doFormat:b n:a.length partten:0];
    }else if (a.length < b.length){
        a = [self doFormat:a n:b.length partten:0];
    }
    [temp insertObject:a atIndex:0];
    [temp insertObject:b atIndex:1];
    return temp;
}
- (NSString *)doFormat:(NSString *)str n:(int)n partten:(int)partten {
    NSMutableString *string = [NSMutableString string];
    for (int i = 0; i < n-str.length; i++) {
        [string appendString:[NSString stringWithFormat:@"%d",partten]];
    }
    [string appendString:str];
    
    return string;
}


// 字符串里面出现的第一个不重复的字符 umu  gogole
- (NSString *)getFirstC:(NSString *)string {
    
    NSMutableString *s = [NSMutableString stringWithString:string];
    NSMutableArray *array = [NSMutableArray array];
     
    for (int i = 0; i < s.length; i++) {
        NSMutableDictionary *dict = [NSMutableDictionary dictionary];
        NSString *c = [s substringWithRange:NSMakeRange(i, 1)];
        NSDictionary *c_dict = [self getIsHave:c array:array index:i];
        if (!c_dict) {
            [dict setValue:@(1) forKey:c];
            [array addObject:dict];
        }
    }
    
    for (int i = 0; i < array.count; i++) {
        NSDictionary *_dict = [array objectAtIndex:i];
        NSNumber *value = [_dict objectForKey:_dict.allKeys.firstObject];
        if (value.intValue == 1) {
            return _dict.allKeys.firstObject;
        }
    }
    return nil;
}


- (NSDictionary *)getIsHave:(NSString *)str array:(NSArray *)array index:(int)index{
    
    for (int i = 0; i< array.count; i++) {
        NSMutableDictionary *_dict = [array objectAtIndex:i];
        NSNumber *value = [_dict objectForKey:str];
        NSString *key = _dict.allKeys.firstObject;
        if ([key isEqualToString:str]) {
            int _value = value.intValue + 1;
            [_dict setValue:@(_value) forKey:str];
            return _dict;
        }
    }
    return nil;
}

@end
