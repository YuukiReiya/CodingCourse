/*!
	@file	EntryPoint.cpp
	@date	2019/06/16
	@author	�ԏ� �G�P
	@brief	�G���g���[�|�C���g
*/
#include <iostream>
#include "Singleton/SingletonSample.h"
#include "Singleton/Sample1.h"
#include "Singleton/Sample2.h"
#include "Adapter/AdapterSample.h"
#include "Visitor/VisitorSample.h"

/*!
	@using	std
	@brief	using�f�B���N�e�B�u
*/
using namespace std;

/*!
	@using	GoF
	@brief	using�f�B���N�e�B�u
*/
using namespace GoF;

/*!
	@def	SINGLETON
	@brief	�V���O���g���̃T���v���R�[�h
	@detail	�R�����g�A�E�g��ON/OFF�؂�ւ����\
*/
//#define SINGLETON

/*!
	@def	ADAPTER
	@brief	�A�_�v�^�[�̃T���v���R�[�h
	@detail	�R�����g�A�E�g��ON/OFF�؂�ւ����\
*/
#define ADAPTER

/*!
	@def	VIVITOR
	@brief	�r�W�^�[�̃T���v���R�[�h
	@detail	�R�����g�A�E�g��ON/OFF�؂�ւ����\
*/
#define VISITOR

//NOTE:	�v���O�����̃G���g���[�|�C���g(���C���֐�)
int main()
{

#pragma region �V���O���g��
#ifdef SINGLETON
	cout << endl;
	cout << "���V���O���g���̃T���v���R�[�h��" << endl;

	//NOTE:	�V���O���g���̃A�N�Z�X�͒����Ȃ肪��
	//			
	//		ex) GoF::Singleton::CSingleton::GetInstance().GetCount()
	//			����ł悤�₭GetCount���Ăяo����B
	//
	//		������!!
	//		using��typedef���g�����ʖ���A�h���X�Q�ƂŎQ�Ɨp�̕ϐ���p�ӂ��Ă����Ɗy�ɂȂ�

	//1.using
	using usingSingeton = GoF::Singleton::CSingleton;
	usingSingeton::GetInstance().GetCount();		//	�Ăяo�����̗�Ȃ̂Ń_�~�[�����Ƃ��ăQ�b�^�[���Ăяo���Ă���

	//2.typedef
	typedef GoF::Singleton::CSingleton typedefSingleton;
	typedefSingleton::GetInstance().GetCount();		//	�Ăяo�����̗�Ȃ̂Ń_�~�[�����Ƃ��ăQ�b�^�[���Ăяo���Ă���

	//3.�A�h���X�Q��
	auto& singleton = GoF::Singleton::CSingleton::GetInstance();//�^���_�g���Ă��邯��"GoF::Singleton::CSingleton"����ł��悵
	singleton.GetCount();							//	�Ăяo�����̗�Ȃ̂Ń_�~�[�����Ƃ��ăQ�b�^�[���Ăяo���Ă���
	//���A�h���X�Q�Ƃ̓R���X�g���N�^��������������藝�����Ȃ��ƁA�q���[�}���G���[�ŕ����o���Ă��܂����Ƃɒ���!!

	//	���ǂ�ł��D���Ȃ̂��ǂ�����
	//	������̓A�h���X�Q�Ƃ����܂��B

	//	�V���O���g���̃J�E���^���m�F
	cout << "�ŏ��̃J�E���^:" << singleton.GetCount() << endl;//	�l��"0"

	singleton.AddCount();
	cout << "Add��̃J�E���^:" << singleton.GetCount() << endl;//	�l��"1"

	//	Singleton::CSample1��2�̕ʃt�@�C���Ɍׂ��Ă���v���O�����ɂ���p���邩�m�F
	Singleton::CSample1*pSingletonSample1 = new Singleton::CSample1;	//�R���X�g���N�^�ŉ��Z���Ă���̂ŉ��Z����Ă���͂�...
	cout << "�T���v��1������̃J�E���^:" << singleton.GetCount() << endl;//	�l��"2"

	Singleton::CSample2*pSingletonSample2 = new Singleton::CSample2;		//�f�X�g���N�^�ŉ��Z���Ă���̂ł܂����Z����Ȃ��͂�...
	cout << "�T���v��2������̃J�E���^:" << singleton.GetCount() << endl;//	�l��"2"

	delete pSingletonSample1;
	cout << "�T���v��1�j����̃J�E���^:" << singleton.GetCount() << endl;//	�l��"2"
	
	delete pSingletonSample2;//�����ŉ��Z�����͂�
	cout << "�T���v��2�j����̃J�E���^:" << singleton.GetCount() << endl;//	�l��"3"

#endif // SINGLETON
#pragma endregion

#pragma region �A�_�v�^�[
#ifdef ADAPTER
	//�Q�l:https://riptutorial.com/ja/cplusplus/example/24704/%E3%82%A2%E3%83%80%E3%83%97%E3%82%BF%E3%83%91%E3%82%BF%E3%83%BC%E3%83%B3

	cout << endl;
	cout<< "���A�_�v�^�[�̃T���v���R�[�h��" << endl;
	//	�ϐ���ʂɒ�`(���R�͌�q)
	Adapter::CPlayer*pAdapterPlayer = new Adapter::CPlayer;
	cout << "Player�̃A�C�e��ID:" << pAdapterPlayer->GetItemCode() << endl;

	//	�A�_�v�^�[�Ń_�E���L���X�g
	Adapter::CItemCollector*pItemCollector = new Adapter::CAdapter;
	

	//	�����"Player"���ł͐錾���Ă��Ȃ�����"GetItem"�֐����Ă񂾂��ƂɂȂ�
	//	����L�̂悤�ɕϐ���ʂŒ�`���Ă��܂����ꍇ�͓��R�A�C���X�^���X���Ⴄ�̂Œl�͕ʂɂȂ�
	//	�@ex)pAdapterPlayer->GetItemCode() �� pItemCollector->GetItemCode();
	pItemCollector->GetItem();
	cout << "Player�̃A�C�e��ID:" << pAdapterPlayer->GetItemCode() << endl;

	//	�������J��
	delete pItemCollector;
	delete pAdapterPlayer;
#endif // ADAPTER
#pragma endregion

#pragma region �r�W�^�[
#ifdef VISITOR

	//Visitor::RangeInObject* rio = new Visitor::RangeInObject;
	//Visitor::CPlayer* pVisitorPlayer = new Visitor::CPlayer;
	//Visitor::CEnemy* pVisitEnemy = new Visitor::CEnemy;
	//Visitor::CItem* pVisitorItem = new Visitor::CItem;

	//	"�v���C���[" : "�G"
	//rio->VisitPlayer(pVisitorPlayer);



#endif // VISITOR
#pragma endregion



	//	���s��}�����Ƃ�
	cout << endl;
	system("pause");
	return 0;
}