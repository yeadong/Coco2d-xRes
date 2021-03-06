/**
*@file 
*@brief 时间进度条
*
*详细概述
*
*@author DionysosLai，email: 906391500@qq.com
*@version 1.0
*@data 2014-7-8 11:54
*/


#ifndef __TIME_SCHEDULE_H__
#define __TIME_SCHEDULE_H__

#include "cocos2d.h"
#include "cocos-ext.h"

class TimeSchedule : public cocos2d::CCNode
{
public:
	TimeSchedule();
	~TimeSchedule();

	static TimeSchedule* create(const unsigned int& totalTime);
	virtual bool init(const unsigned int& totalTime);
	virtual void update(float delta);

public:
///@brief 开始计时
///@return 说明
	void startTimeProgrss();

///@brief 停止时间计时
///@return 说明
	void stopTimeProgress();

///@brief 增加时间
///@param[in] time---增加的时间 timeGap---多久增加一次时间
///@pre 增加后的时间不能高于最高时间
///@return 说明
	void addTime(const unsigned int& time, const float& timeGap);

///@brief 减少时间
///@param[in] time---减少的时间
///@return 说明
	void reduceTime(const unsigned int& time, const float& timeGap);

///@brief 时间流速调整
///@param[in] times---倍数  timeLast
///@pre times大于0---时间加速消失， 小于0---即时间， -1--时间静止
///@return 说明
	void adjustTime(const float& times, unsigned int& timeLast);

///@brief 复位
///@param[in]  timeGap---花多少时间复位 
///@return 
	void resetTime(const float& timeGap);
///@brief 复位
///@return 
	void resetTime();

	CC_SYNTHESIZE(float, m_fTotalTime, TotalTime);		///< 总时间
private:
///@brief 进度条类初始化
///@return 说明
	void initData(const unsigned int& totalTime);

///@brief 控制增加时间速度
///@param[in/out] 
///@pre 前者条件 
///@return 
	void addTimeSpeed(float delta);

///@brief 控制减少时间速度
///@return 
	void reduceTimeSpeed(float delta);

private:
	cocos2d::CCSprite* m_pButtom;		///< 底板
	cocos2d::CCSprite* m_pProgress;		///< 进度条
	cocos2d::CCSprite* m_pProgressRight;///< 进度条右部
	cocos2d::CCTexture2D* m_pText2d;	///< 进度条

	float m_fCurrentTime;				///< 当前时间
	float m_fTimeLength;				///< 进度条
	float m_fAddTime;					///< 当前增加时间
	float m_fReduceTime;				///< 当前减少时间
/*	float m_fAddTimeTotal;				///< 增加总的时间*/
};
#endif	///< (__TIME_SCHEDULE_H__)