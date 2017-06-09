/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2012-2015. All rights reserved.
 * foss@huawei.com
 *
 * If distributed as part of the Linux kernel, the following license terms
 * apply:
 *
 * * This program is free software; you can redistribute it and/or modify
 * * it under the terms of the GNU General Public License version 2 and
 * * only version 2 as published by the Free Software Foundation.
 * *
 * * This program is distributed in the hope that it will be useful,
 * * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * * GNU General Public License for more details.
 * *
 * * You should have received a copy of the GNU General Public License
 * * along with this program; if not, write to the Free Software
 * * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA
 *
 * Otherwise, the following license terms apply:
 *
 * * Redistribution and use in source and binary forms, with or without
 * * modification, are permitted provided that the following conditions
 * * are met:
 * * 1) Redistributions of source code must retain the above copyright
 * *    notice, this list of conditions and the following disclaimer.
 * * 2) Redistributions in binary form must reproduce the above copyright
 * *    notice, this list of conditions and the following disclaimer in the
 * *    documentation and/or other materials provided with the distribution.
 * * 3) Neither the name of Huawei nor the names of its contributors may
 * *    be used to endorse or promote products derived from this software
 * *    without specific prior written permission.
 *
 * * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */


#ifndef __IMMINTERFACE_H__
#define __IMMINTERFACE_H__


/*****************************************************************************
  1 其他头文件包含
*****************************************************************************/
#include "vos.h"
#include "product_config.h"
#include "IMMmem_PS.h"

#if (defined(CONFIG_BALONG_SPE) && (VOS_LINUX == VOS_OS_VER))
#include "mdrv_spe_wport.h"
#endif /* CONFIG_BALONG_SPE */

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#pragma pack(4)


/*****************************************************************************
  2 宏定义
*****************************************************************************/
#define IMM_MAX_ETH_FRAME_LEN           (1536)
#define IMM_MAC_HEADER_RES_LEN          (14)
#define IMM_INVALID_VALUE               (0xFFFFFFFF)


/*****************************************************************************
  3 枚举定义
*****************************************************************************/


/*****************************************************************************
  4 全局变量声明
*****************************************************************************/


/*****************************************************************************
  5 消息头定义
*****************************************************************************/


/*****************************************************************************
  6 消息定义
*****************************************************************************/


/*****************************************************************************
  7 STRUCT定义
*****************************************************************************/

/*****************************************************************************
  8 UNION定义
*****************************************************************************/


/*****************************************************************************
  9 OTHERS定义
*****************************************************************************/


/*****************************************************************************
  10 函数声明
*****************************************************************************/


/*****************************************************************************
 函 数 名  : IMM_ZcStaticAlloc
 功能描述  : 此分配函数用于在ACPU上申请数传使用的内存
 输入参数  : ulLen - 申请的字节数
 输出参数  : 无
 返 回 值  : 无
 调用函数  : 成功：返回指向IMM_ZC_STRU的指针
             失败：返回NULL；
 被调函数  :
 说    明  :

 修改历史      :
  1.日    期   : 2011年12月1日
    作    者   : y00171741
    修改内容   : 新生成函数

*****************************************************************************/
extern IMM_ZC_STRU* IMM_ZcStaticAlloc_Debug(unsigned short usFileID, unsigned short usLineNums,
            unsigned int ulLen);

#define    IMM_ZcStaticAlloc(ulLen)\
    IMM_ZcStaticAlloc_Debug(THIS_FILE_ID, __LINE__, (ulLen))



/*****************************************************************************
 函 数 名  : IMM_ZcLargeMemAlloc
 功能描述  : 从Linux系统中申请内存的分配函数
 输入参数  : ulLen - 申请的字节数
 输出参数  : 无
 返 回 值  : 无
 调用函数  : 成功：返回指向IMM_ZC_STRU的指针
             失败：返回NULL；
 被调函数  :

 修改历史      :
  1.日    期   : 2011年12月1日
    作    者   : y00171741
    修改内容   : 新生成函数

*****************************************************************************/
#define IMM_ZcLargeMemAlloc(ulLen)  dev_alloc_skb((ulLen))

/*****************************************************************************
 函 数 名  : IMM_DataTransformImmZc
 功能描述  : 申请IMM_ZC_STRU控制头并把C核跨核共享内存挂接到IMM_ZC_STRU上
 输入参数  : pucData - 数据块首地址
             ulLen - 数据块长度(byte)
             pstTtfMem - 保存C核的地址，C核指向TTF_MEM的地址
 输出参数  : 无
 返 回 值  : 无
 调用函数  : 成功：返回指向IMM_ZC_STRU的指针
             失败：返回NULL；
 被调函数  :
 说    明  : 此函数区分产品的形态, 如MBB上此接口有效, 智能机上返回空指针

 修改历史      :
  1.日    期   : 2011年12月1日
    作    者   : y00171741
    修改内容   : 新生成函数

*****************************************************************************/
extern IMM_ZC_STRU * IMM_ZcDataTransformImmZc_Debug(unsigned short usFileID,
            unsigned short usLineNum, const unsigned char *pucData, unsigned int ulLen, void *pstTtfMem);


#define IMM_DataTransformImmZc(pucData, ulLen, pstTtfMem)\
    IMM_ZcDataTransformImmZc_Debug(THIS_FILE_ID, __LINE__, (pucData), (ulLen), (pstTtfMem))


/*****************************************************************************
 函 数 名  : IMM_ZcStaticCopy
 功能描述  : IMM_ZC的数据结构的拷贝（控制节点和数据块），把数据块从Linux自带的内存拷贝到A核共享内存
 输入参数  : pstImmZc - 源数据结构
 输出参数  : 无
 返 回 值  : 成功：返回目的IMM_ZC_STRU的指针
             失败：返回NULL；
 调用函数  :
 被调函数  :
 说    明  : 此函数区分产品的形态, 如MBB上此接口有效, 智能机上返回空指针
             MBB上, A核数据类型为MEM_TYPE_SYS_DEFINED的数据块, 数据传给C核前,
             一定要调用本接口, 将数据拷贝到A核共享内存。
 修改历史      :
  1.日    期   : 2011年12月1日
    作    者   : y00171741
    修改内容   : 新生成函数

*****************************************************************************/
extern  IMM_ZC_STRU* IMM_ZcStaticCopy_Debug(VOS_UINT16 usFileID, VOS_UINT16 usLineNums, IMM_ZC_STRU* pstImmZc);

#define IMM_ZcStaticCopy(pstImmZc)\
    IMM_ZcStaticCopy_Debug(THIS_FILE_ID, __LINE__, (pstImmZc))

/*****************************************************************************
 函 数 名  : IMM_ZcFree
 功能描述  : 释放IMM_ZC_STRU内存
 输入参数  : pstImmZc - 指向IMM_ZC_STRU的指针
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :
 修改历史      :
  1.日    期   : 2011年12月1日
    作    者   : y00171741
    修改内容   : 新生成函数

*****************************************************************************/
#if (defined(CONFIG_BALONG_SPE) && (VOS_LINUX == VOS_OS_VER))
#define IMM_ZcFree( pstImmZc )              mdrv_spe_wport_recycle((pstImmZc))
#else
#define IMM_ZcFree( pstImmZc )              kfree_skb((pstImmZc))
#endif

/*****************************************************************************
 函 数 名  : IMM_ZcFreeAny
 功能描述  : 释放IMM_ZC_STRU内存
 输入参数  : pstImmZc - 指向IMM_ZC_STRU的指针
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :
 修改历史      :
  1.日    期   : 2017年1月22日
    作    者   : l00373346
    修改内容   : 新生成函数

*****************************************************************************/
#if (defined(CONFIG_BALONG_SPE) && (VOS_LINUX == VOS_OS_VER))
#define IMM_ZcFreeAny( pstImmZc )              mdrv_spe_wport_recycle((pstImmZc))
#else
#define IMM_ZcFreeAny( pstImmZc )              dev_kfree_skb_any((pstImmZc))
#endif

/*****************************************************************************
 函 数 名  : IMM_ZcHeadFree
 功能描述  : 释放IMM_ZC_STRU控制节点，数据块不释放。
 输入参数  : pstImmZc - 指向IMM_ZC_STRU的指针
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :
 修改历史      :
  1.日    期   : 2011年12月1日
    作    者   : y00171741
    修改内容   : 新生成函数

*****************************************************************************/
extern void IMM_ZcHeadFree(IMM_ZC_STRU* pstImmZc);

/*****************************************************************************
 函 数 名  : IMM_RemoteFreeTtfMem
 功能描述  : 释放远端TTF_Mem。
 输入参数  : pucAddr - 指向C核的TTF_MEM的指针
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :
 修改历史      :
  1.日    期   : 2011年12月1日
    作    者   : y00171741
    修改内容   : 新生成函数

*****************************************************************************/
extern VOS_VOID IMM_RbRemoteFreeMem(VOS_VOID *pucAddr);

#define IMM_RemoteFreeTtfMem(pucAddr)     IMM_RbRemoteFreeMem((pucAddr))


/*****************************************************************************
 函 数 名  : IMM_ZcAddMacHead
 功能描述  : 添加MAC头。
 输入参数  : pstImmZc - 指向IMM_ZC_STRU的指针
             pucAddData - 添加的MAC头首地址
             usLen - MAC头的长度
 输出参数  : 无
 返 回 值  : 操作成功与否, VOS_OK - 成功, VOS_ERR - 失败
 调用函数  :
 被调函数  :
 说    明  : 此函数区分产品的形态, 如MBB上此接口有效, 智能机上返回ERR

 修改历史      :
  1.日    期   : 2011年12月1日
    作    者   : y00171741
    修改内容   : 新生成函数

*****************************************************************************/
extern unsigned int IMM_ZcAddMacHead (IMM_ZC_STRU *pstImmZc, const unsigned char * pucAddData);

/*****************************************************************************
 函 数 名  : IMM_ZcRemoveMacHead
 功能描述  : 从以太帧中剥去MAC头。
 输入参数  : pstImmZc - 指向IMM_ZC_STRU的指针
 输出参数  : 无
 返 回 值  : 操作成功与否, VOS_OK - 成功, VOS_ERR - 失败
 调用函数  :
 被调函数  :
 说    明  : 此函数区分产品的形态, 如MBB上此接口有效, 智能机上返回ERR

 修改历史      :
  1.日    期   : 2011年12月1日
    作    者   : y00171741
    修改内容   : 新生成函数

*****************************************************************************/
extern unsigned int IMM_ZcRemoveMacHead (IMM_ZC_STRU *pstImmZc);

/*****************************************************************************
 函 数 名  : IMM_ZcMapToImmMem
 功能描述  : A核把IMM_ZC零拷贝控制节点转换成IMM_Mem控制节点。
 输入参数  : pstImmZc - 指向IMM_ZC_STRU的指针
 输出参数  : 无
 返 回 值  : 返回IMM_MEM_STRU的指针。
 调用函数  :
 被调函数  :
 说    明  : 此函数区分产品的形态, 如MBB上此接口有效, 智能机上返回空指针

 修改历史      :
  1.日    期   : 2011年12月1日
    作    者   : y00171741
    修改内容   : 新生成函数

*****************************************************************************/
extern IMM_MEM_STRU *IMM_ZcMapToImmMem_Debug(unsigned short usFileID,
            unsigned short usLineNum, IMM_ZC_STRU *pstImmZc);


#define IMM_ZcMapToImmMem(pstImmZc)\
    IMM_ZcMapToImmMem_Debug(THIS_FILE_ID, __LINE__, (pstImmZc))


/*****************************************************************************
 函 数 名  : IMM_ZcPush
 功能描述  : 数据添加到有效数据块的头部。
 输入参数  : pstImmZc - 指向IMM_ZC_STRU的指针
             ulLen - 添加数据的长度
 输出参数  : 无
 返 回 值  : 返回的数据块首地址，并且是添加数据之后的数据块地址。
 调用函数  :
 被调函数  :
 其它      : 本接口只移动指针；
             数据添加到有效数据块的头部之前,调用本接口
 修改历史      :
  1.日    期   : 2011年12月1日
    作    者   : y00171741
    修改内容   : 新生成函数

*****************************************************************************/
#define IMM_ZcPush(pstImmZc,ulLen)          skb_push((pstImmZc),(ulLen))


/*****************************************************************************
 函 数 名  : IMM_ZcPull
 功能描述  : 从IMM_ZC指向的数据块的头部取出数据。
 输入参数  : pstImmZc - 指向IMM_ZC_STRU的指针
             ulLen - 取出数据的长度
 输出参数  : 无
 返 回 值  : 返回的数据块首地址，并且是取出数据之后的地址。
 调用函数  :
 被调函数  :
 其它      : 本接口只移动指针；
 修改历史      :
  1.日    期   : 2011年12月1日
    作    者   : y00171741
    修改内容   : 新生成函数

*****************************************************************************/
#define IMM_ZcPull(pstImmZc,ulLen)          skb_pull((pstImmZc),(ulLen))


/*****************************************************************************
 函 数 名  : IMM_ZcPut
 功能描述  : 添加数据在IMM_ZC指向的数据块的尾部。
 输入参数  : pstImmZc - 指向IMM_ZC_STRU的指针
             ulLen - 添加数据的长度
 输出参数  : 无
 返 回 值  : 返回的数据块尾部地址，并且是添加数据之前的数据块尾部地址。
 调用函数  :
 被调函数  :
 其它      : 本接口只移动指针；
 修改历史      :
  1.日    期   : 2011年12月1日
    作    者   : y00171741
    修改内容   : 新生成函数

*****************************************************************************/
#define IMM_ZcPut(pstImmZc,ulLen)           skb_put((pstImmZc),(ulLen))


/*****************************************************************************
 函 数 名  : IMM_ZcReserve
 功能描述  : 预留IMM_ZC指向的数据块头部空间。
 输入参数  : pstImmZc - 指向IMM_ZC_STRU的指针
             ulLen - 预留数据头部的空间(byte)
 输出参数  : 无
 返 回 值  : 无。
 调用函数  :
 被调函数  :
 说    明  : 本接口只移动指针，为头部预留空间。
             只用于刚分配的IMM_ZC,IMM_ZC指向的数据块还没有使用；
 修改历史      :
  1.日    期   : 2011年12月1日
    作    者   : y00171741
    修改内容   : 新生成函数

*****************************************************************************/
#define IMM_ZcReserve(pstImmZc,ulLen)       skb_reserve((pstImmZc),(int)(ulLen))


/*****************************************************************************
 函 数 名  : IMM_ZcResetTailPoint
 功能描述  : 重置IMM_ZC尾部地址
 输入参数  : pstImmZc --- 指向IMM_ZC_STRU的指针
 输出参数  : 无
 返 回 值  : void
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2015年10月06日
    作    者   : A00165503
    修改内容   : 新生成函数

*****************************************************************************/
#define IMM_ZcResetTailPointer(pstImmZc)    skb_reset_tail_pointer((pstImmZc))


/*****************************************************************************
 函 数 名  : IMM_ZcHeadRoom
 功能描述  : 得到数据头部预留空间字节数。
 输入参数  : pstImmZc - 指向IMM_ZC_STRU的指针
 输出参数  : 无
 返 回 值  : 预留空间字节数。
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2011年12月1日
    作    者   : y00171741
    修改内容   : 新生成函数

*****************************************************************************/
#define IMM_ZcHeadRoom(pstImmZc)            skb_headroom((pstImmZc))


/*****************************************************************************
 函 数 名  : IMM_ZcTailRoom
 功能描述  : 得到数据尾部预留空间字节数。
 输入参数  : pstImmZc - 指向IMM_ZC_STRU的指针
 输出参数  : 无
 返 回 值  : 预留空间字节数。
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2011年12月1日
    作    者   : y00171741
    修改内容   : 新生成函数

*****************************************************************************/
#define IMM_ZcTailRoom(pstImmZc)            skb_tailroom((pstImmZc))


/*****************************************************************************
 函 数 名  : IMM_ZcGetDataPtr
 功能描述  : 得到数据块首地址。
 输入参数  : pstImmZc - 指向IMM_ZC_STRU的指针
 输出参数  : 无
 返 回 值  : 数据块首地址。
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2011年12月1日
    作    者   : y00171741
    修改内容   : 新生成函数

*****************************************************************************/
#define IMM_ZcGetDataPtr(pstImmZc)          ((pstImmZc)->data)


/*****************************************************************************
 函 数 名  : IMM_ZcGetUsedLen
 功能描述  : 得到数据块使用的字节数。
 输入参数  : pstImmZc - 指向IMM_ZC_STRU的指针
 输出参数  : 无
 返 回 值  : 数据块使用的字节数。
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2011年12月1日
    作    者   : y00171741
    修改内容   : 新生成函数

*****************************************************************************/
#define IMM_ZcGetUsedLen(pstImmZc)          ((pstImmZc)->len)


/*****************************************************************************
 函 数 名  : IMM_ZcGetUserApp
 功能描述  : 得到UserApp。
 输入参数  : pstImmZc - 指向IMM_ZC_STRU的指针
 输出参数  : 无
 返 回 值  : 得到UserApp。
 调用函数  :
 被调函数  :
 说    明  : 区分MBB和智能机形态, MBB上此接口有效, 智能机上无效, 直接返回0
             因此要求外部使用者代码隔离

 修改历史      :
  1.日    期   : 2011年12月1日
    作    者   : y00171741
    修改内容   : 新生成函数

*****************************************************************************/
extern unsigned short IMM_ZcGetUserApp(IMM_ZC_STRU *pstImmZc);


/*****************************************************************************
 函 数 名  : IMM_ZcSetUserApp
 功能描述  : 设置UserApp。
 输入参数  : pstImmZc - 指向IMM_ZC_STRU的指针
             usApp - 用户自定义
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :
 说    明  : 区分MBB和智能机形态, MBB上此接口有效, 智能机上无效, 为空函数
             因此要求外部使用者代码隔离

 修改历史      :
  1.日    期   : 2011年12月1日
    作    者   : y00171741
    修改内容   : 新生成函数

*****************************************************************************/
extern void IMM_ZcSetUserApp (IMM_ZC_STRU *pstImmZc, unsigned short usApp);


/*****************************************************************************
 函 数 名  : IMM_ZcQueueHeadInit
 功能描述  : 队列初始化。
 输入参数  : pstList - 指向IMM_ZC_HEAD_STRU的指针
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2011年12月1日
    作    者   : y00171741
    修改内容   : 新生成函数

*****************************************************************************/
#define IMM_ZcQueueHeadInit(pstList)        skb_queue_head_init((pstList))


/*****************************************************************************
 函 数 名  : IMM_ZcQueueHead
 功能描述  : 元素插入队列头部。
 输入参数  : pstList - 指向IMM_ZC_HEAD_STRU的指针
             pstNew  - 插入的元素，是指向IMM_ZC_STRU的指针
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2011年12月1日
    作    者   : y00171741
    修改内容   : 新生成函数

*****************************************************************************/
#define IMM_ZcQueueHead(pstList,pstNew)     skb_queue_head((pstList),(pstNew))


/*****************************************************************************
 函 数 名  : IMM_ZcQueueTail
 功能描述  : 元素插入队列尾部 。
 输入参数  : pstList - 指向IMM_ZC_HEAD_STRU的指针
             pstNew  - 插入的元素，是指向IMM_ZC_STRU的指针
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2011年12月1日
    作    者   : y00171741
    修改内容   : 新生成函数

*****************************************************************************/
#define IMM_ZcQueueTail(pstList,pstNew)     skb_queue_tail((pstList),(pstNew))


/*****************************************************************************
 函 数 名  : IMM_ZcDequeueHead
 功能描述  : 从队列头部 取元素 。
 输入参数  : pstList - 指向IMM_ZC_HEAD_STRU的指针
 输出参数  : 无
 返 回 值  : 指向IMM_ZC_STRU的指针
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2011年12月1日
    作    者   : y00171741
    修改内容   : 新生成函数

*****************************************************************************/
#define IMM_ZcDequeueHead(pstList)          skb_dequeue((pstList))


/*****************************************************************************
 函 数 名  : IMM_ZcDequeueTail
 功能描述  : 从队列尾部取元素 。
 输入参数  : pstList - 指向IMM_ZC_HEAD_STRU的指针
 输出参数  : 无
 返 回 值  : 指向IMM_ZC_STRU的指针
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2011年12月1日
    作    者   : y00171741
    修改内容   : 新生成函数

*****************************************************************************/
#define IMM_ZcDequeueTail(pstList)          skb_dequeue_tail((pstList))


/*****************************************************************************
 函 数 名  : IMM_ZcQueueLen
 功能描述  : 得到队列中的元素的数目。
 输入参数  : pstList - 指向IMM_ZC_HEAD_STRU的指针
 输出参数  : 无
 返 回 值  : 得到队列中的元素的数目。
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2011年12月1日
    作    者   : y00171741
    修改内容   : 新生成函数

*****************************************************************************/
#define IMM_ZcQueueLen(pstList)             skb_queue_len((pstList))


/*****************************************************************************
 函 数 名  : IMM_ZcQueuePeek
 功能描述  : 得到队列中的队首元素的指针
 输入参数  : pstList - 指向IMM_ZC_HEAD_STRU的指针
 输出参数  : 无
 返 回 值  : 指向队首元素的指针
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年8月11日
    作    者   : liukai
    修改内容   : 新生成函数

*****************************************************************************/
#define IMM_ZcQueuePeek(pstList)            skb_peek((pstList))


/*****************************************************************************
 函 数 名  : IMM_ZcQueuePeekTail
 功能描述  : 得到队列中的队尾元素的指针
 输入参数  : pstList - 指向IMM_ZC_HEAD_STRU的指针
 输出参数  : 无
 返 回 值  : 指向队尾元素的指针
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年8月11日
    作    者   : liukai
    修改内容   : 新生成函数

*****************************************************************************/
#define IMM_ZcQueuePeekTail(pstList)        skb_peek_tail((pstList))


/*****************************************************************************
 函 数 名  : IMM_MntnAcpuCheckMemPoolLeak
 功能描述  : 提供给外部模块调用检查A核内存是否泄露
 输入参数  : VOS_VOID
 输出参数  : 无
 返 回 值  : VOS_VOID
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2012年1月13日
    作    者   : s00164817
    修改内容   : 新生成函数

*****************************************************************************/
VOS_VOID IMM_MntnAcpuCheckPoolLeak( VOS_VOID );


#if (VOS_OS_VER == VOS_WIN32)
#pragma pack()
#else
#pragma pack(0)
#endif




#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of ImmInterface.h */

