// �w�b�_�t�@�C���̃C���N���[�h
// ����̃w�b�_
#include <tchar.h>	// TCHAR�^
#include <stdio.h>	// �W�����o��

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �R�}���h�����̏���.
	if (argc == 1){	// argc��1�̎�.

		// "Hello, OneLang!"�Əo��.
		_tprintf(_T("Hello, OneLang!\n"));	// "Hello, OneLang!"�Əo��.

	}
	else{	// argc��2�ȏ�̎�.(Win32Console��argc��0�ɂȂ�Ȃ�����.)

		// �R���p�C���Ώۂ̃\�[�X�R�[�h�t�@�C�������o��.
		_tprintf(_T("argv[1] = %s\n"), argv[1]);	// _tprintf��argv[1]���o��.

	}

	// �v���O�����̏I��
	return 0;	// return��0��Ԃ��Đ���I��.

}