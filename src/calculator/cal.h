/*
 * cal.h
 * 如果要让C++能调用，就必须声明 extern "C"，extern需要配合 __cplusplus
 *
 *  Created on: 2020年12月22日
 *      Author: kevin
 */

#ifndef SRC_CALCULATOR_CAL_H_
#define SRC_CALCULATOR_CAL_H_

#ifdef __cplusplus
extern "C" {
#endif
    int add(int a, int b);
    int divid(int a, int b);
#ifdef __cplusplus
}
#endif

#endif /* SRC_CALCULATOR_CAL_H_ */
