#pragma once

#include "../../Define/KDefine+Global.h"
#include "../../Utility/Interface/IReleasable.h"
#include "../../Utility/Interface/IUpdateable.h"
#include "../../Utility/Interface/IRenderable.h"

/**
 * 객체
 */
class CObj : public virtual IReleasable, public virtual IUpdateable, public virtual IRenderable
{
public:			// IUpdateable

	/** 상태를 갱신한다 */
	virtual void Update(float a_fTime_Delta) final override;

	/** 상태를 갱신한다 */
	virtual void LateUpdate(float a_fTime_Delta) final override;

public:			// IRenderable

	/** 객체를 그린다 */
	virtual void Render(ID3D10Device* a_pDevice) final override;

	/** 객체를 그린다 */
	virtual void LateRender(ID3D10Device* a_pDevice) final override;

	/** 객체를 그린다 */
	virtual void LateRender(ID3DX10Sprite* a_pXSprite) final override;

public:			// public 함수

	/** 생성자 */
	CObj(void);

	/** 소멸자 */
	virtual ~CObj(void) = 0;

	/** 자식 객체를 추가한다 */
	void AddChild(CObj* a_pChild);

	/** 자식 객체를 제거한다 */
	void RemoveChild(CObj* a_pChild);

	/** 위치 프로퍼티 */
	GETTER_SETTER_PROPERTY(D3DXVECTOR3, Pos, m_stPos);

	/** 비율 프로퍼티 */
	GETTER_SETTER_PROPERTY(D3DXVECTOR3, Scale, m_stScale);

	/** 회전 프로퍼티 */
	GETTER_SETTER_PROPERTY(D3DXVECTOR3, Rotate, m_stRotate);

public:			// public 접근 함수

	/** 로컬 X 축 방향을 반환한다 */
	virtual D3DXVECTOR3 GetVec_LocalRight(void) const;

	/** 로컬 Y 축 방향을 반환한다 */
	virtual D3DXVECTOR3 GetVec_LocalUp(void) const;

	/** 로컬 Z 축 방향을 반환한다 */
	virtual D3DXVECTOR3 GetVec_LocalForward(void) const;

	/** 월드 X 축 방향을 반환한다 */
	virtual D3DXVECTOR3 GetVec_WorldRight(void) const;

	/** 월드 Y 축 방향을 반환한다 */
	virtual D3DXVECTOR3 GetVec_WorldUp(void) const;

	/** 월드 Z 축 방향을 반환한다 */
	virtual D3DXVECTOR3 GetVec_WorldForward(void) const;

	/** 로컬 변환 행렬을 반환한다 */
	virtual D3DXMATRIXA16 GetMatrix_LocalTrans(void) const;

	/** 월드 변환 행렬을 반환한다 */
	virtual D3DXMATRIXA16 GetMatrix_WorldTrans(void) const;

protected:			// protected 함수

	/** 상태를 갱신한다 */
	virtual void OnUpdate(float a_fTime_Delta);

	/** 상태를 갱신한다 */
	virtual void OnLateUpdate(float a_fTime_Delta);

	/** 객체를 그린다 */
	virtual void OnRender(ID3D10Device* a_pDevice);

	/** 객체를 그린다 */
	virtual void OnLateRender(ID3D10Device* a_pDevice);

	/** 객체를 그린다 */
	virtual void OnLateRender(ID3DX10Sprite* a_pXSprite);

private:			// private 접근 함수

	/** 부모 객체 월드 변환 행렬을 반환한다 */
	virtual D3DXMATRIXA16 GetMatrix_ParentWorldTrans(void) const;

private:			// private 변수

	CObj* m_pParent = nullptr;
	std::vector<CObj*> m_oVectorChildren;
};