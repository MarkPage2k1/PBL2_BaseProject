#include "WordQuestion.h"
#include <string>
#include <Windows.h>
#include <vector>
#include "mmsystem.h"
#include <ctime>

// ========== BEGIN: CLASS WORD QUESTION ========== //
Node_wq::Node_wq(string _wqId, string _wId, string _fqId, string _mqId)
	: wq_id(_wqId), w_id(_wId), fq_id(_fqId), mq_id(_mqId)
{
	// ...
}

Node_wq::~Node_wq()
{
	delete next;
}

Linked_WQ::Linked_WQ()
{
	head = NULL;
}
Linked_WQ::~Linked_WQ()
{
	// ...
}


int Linked_WQ::IsEmpty()
{
	return (this->head == NULL);
}

void Linked_WQ::Search()
{
	Node_wq* P;
	P = this->head;
	string _wqId;
	wcin.ignore();
	cout << "Nhap id tu ban muon tim: ";
	getline(cin, _wqId);
	while (P != NULL && P->wq_id != _wqId)
	{
		P = P->next;
	}
	if (P == NULL) cout << "Khong co tu can tim!!!\n";
	else cout << "Da tim thay tu ban can tim!!! \n";
}

void Linked_WQ::Output()
{
	Node_wq* P;
	P = head;
	while (P != NULL)
	{
		cout << "\nWord Question ID: " << P->wq_id;
		cout << "\nWord ID:  " << P->w_id;
		cout << "\nFill Question ID: " << P->fq_id;
		cout << "\nMutil Question ID: " << P->mq_id;
		cout << "\n\n";
		P = P->next;
	}
	wcout << endl;
}


void Linked_WQ::Insert_first(string _wqId, string _wId, string _fqId, string _mqId)
{
	Node_wq* P;
	P = new Node_wq;
	P->wq_id = _wqId;
	P->w_id = _wId;
	P->fq_id = _fqId;
	P->mq_id = _mqId;
	P->next = head;
	head = P;
}

void Linked_WQ::Insert_last(string _wqId, string _wId, string _fqId, string _mqId)
{
	Node_wq* P;
	Node_wq* temp;
	P = new Node_wq;
	P->wq_id = _wqId;
	P->w_id = _wId;
	P->fq_id = _fqId;
	P->mq_id = _mqId;
	if (head == NULL)
	{
		head = P;
	}
	else
	{
		temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = P;
	}
}
// ========== END: CLASS WORD QUESTION ========== //


void Linked_WQ::LearnWord(Linked_MQ& MQ, Linked_FQ& FQ, Linked_UHW& UHW, User& US)
{
	// =========================================
	//cout << "Da vao Test" << endl;
	//int id = 0;
	
	int EXP = 0; // Diem kinh nghiem
	int i;
	int QS;
	int tmp = 0;
	int HisQS;
	string* ID = new string[5];		// Lưu danh sách câu hỏi được lấy
	string* WR = new string[5];		// Lưu danh sách từ đã học
	int* countID = new int[5];		// Đếm số lần xuất hiện của 1 câu hỏi
	int* checkAS = new int[5];		// Đếm câu hỏi trả lời sai hay đúng để chỉnh mức độ khó của từ
	Node_wq* P = this->head;						// con tro P cua word question
	Node_wq* P_temp = this->head;				// P_temp để lưu vị trí bắt đầu lấy câu hỏi
	//Node_uhw* P_uhw;				// con tro P cua User has word
	// P = this->head;
	//P_uhw = UHW.getUHW();			// con tro head cua Linked_UHW

	// ==================================
	
	int id = 0;
	int size = 0;
	while (P != NULL)		
	{
		if (id == 5) break;	// Lưu 5 ID của bảng Word Question vào mảng string[5]
		while ((P != NULL) && UHW.searchIDW(P->w_id) == 1)	// Kiểm tra từ này đã được học hay chưa?
		{
			//cout << P_uhw->w_id << " = " << P->w_id << endl;
			//cout << "Hoc roi" << endl;
			P = P->next;
			P_temp = P_temp->next;
		
		}
		if (P != NULL)	// Lỡ đã học full từ (Nhưng mà nên xét từ đầu để đỡ tốn time)
		{
			ID[id] = P->wq_id;
			WR[id] = P->w_id;
			countID[id] = 0;
			checkAS[id] = 0;
			P = P->next;
			id++;
		}
		
	}
	size = id;
	if (size == 0)
	{
		cout << "Da hoc het tu." << endl;
		return;
	}
	
	/*
	id = 0;
	P = P_temp;
	while (P != NULL)
	{
		if (id == 5) break;
		cout << ID[id] << ": " << countID[id] << endl;
		cout << P->wq_id << endl;
		P = P ->next;
		id++;
	}
	*/
	int maxAnswer = 0;		// Tổng có 20 câu hỏi
	QS = rand() % size;		// Random từ 0 - > 4 (mỗi lần học chỉ được học 5 từ)
	HisQS = QS;				// Câu hỏi đã đưa ra trước đó.

	while (maxAnswer < size*4)
	{
		//P = this->head;
	    //i = 0;
		//id = 0;
		// [a, b] = a + rand() % (b + 1 - a)
		QS = rand() % size;	// Random lại để khác HisQS
		// khong hop li
		while (QS == HisQS)	// Kiểm tra xem câu hỏi được đưa ra có giống với câu hỏi trước đó hay không?
		{
			if (size*4 - (maxAnswer + 1) > 4)	// Kiểm tra thử số câu hỏi còn lại có lớn hơn 4 hay không?
			{
				QS = rand() % size;
				//HisQS = QS;
			}
			else break;
		}
		HisQS = QS;
		//cout << QS << endl;
		// khong hop li, no chi o trong pham vi 0 -> 4
		int i = 0;	
		P = P_temp;		// Vị trí bắt đầu lấy câu hỏi
		while (P != NULL && i != QS)	// Lấy câu hỏi theo random
		{
			P = P->next;
			i++;
		}
		if (P == NULL)
		{
			cout << "Khong cau hoi trong WQ!!!\n";
			break;
		}
		else
		{
			//int id = 0;
			// ===============
			//cout << P->wq_id << endl;
			//cout << ID[0] << endl;
			id = 0;
			cout << P->wq_id << " <=> " << ID[id] << endl;
			while (P->wq_id != ID[id])		// Tìm vị trí câu hỏi được đưa ra
			{
				cout << P->wq_id << " != " << ID[id] << endl;
				id++;
			}
			cout << P->wq_id << " = " << ID[i] << endl;
			// ==========================
			
			if (countID[id] < 4)
			{
				cout << "Cau thu " << maxAnswer + 1 << ":" << endl;
				if (tmp == 0)
				{
					if (MQ.OutQuestion(P->mq_id) == 1)	// tra loi dung
					{
						EXP += 15;
						cout << "EXP = " << EXP << endl;
					}
					else
					{
						cout << "EXP = " << EXP << endl;
						checkAS[id]++;
					}
					tmp += 1;	// Để xen kẻ 1 câu hỏi nghe, 1 câu hỏi chọn ĐA
				}
				else
				{
					if (FQ.OutQuestion(P->fq_id) == 1)
					{
						EXP += 15;
						cout << "EXP = " << EXP << endl;
					}
					else
					{
						cout << "EXP = " << EXP << endl;
						checkAS[id]++;
					}
					tmp -= 1;
				}
				countID[id]++;
				maxAnswer++;
			}	
			//cout << P->mq_id << endl;
			
		}	
	}
	//=====
	
	
	id = 0;
	while (id < size)
	{
		cout << ID[id] << ": " << checkAS[id] << endl;
		id++;
	}
	
	US.SetEXP(US.GetEXP() + EXP);	// Cong vao diem kinh nghiem nguoi dung
	PlaySound(MAKEINTRESOURCE(9093), GetModuleHandle(NULL), SND_RESOURCE);	// Am thanh hoan thanh
	// Sau khi hoc xong, luu word ID vao bang use has word
	int WordDiff = 0;
	time_t baygio = time(0);	// time hien tai
	for (int i = 0; i < size; i++)
	{
		if (checkAS[i] > 2) WordDiff = 1;
		else WordDiff = 0;
		UHW.AddWordHadLearnt(WR[i], 1, baygio/3600, WordDiff, 5);
		cout << WR[i] << endl;
	}
	UHW.setFlags(1);
	// Xoa mang phu
	delete[] ID;
	delete[] WR;
	delete[] countID;
	delete[] checkAS;

}

void Linked_WQ::Exercise(Linked_MQ& MQ, Linked_FQ& FQ, Linked_UHW& UHW, User& US)
{
	MyLib mylib;
	time_t baygio = time(0) / 3600;	// time hien tai
	int EXP = 0; // Diem kinh nghiem
	int i;
	int QS;
	int tmp = 0;
	int HisQS;
	string* ID = new string[5];		// Lưu danh sách câu hỏi được lấy
	string* WR = new string[5];		// Lưu danh sách từ đã học
	int* countID = new int[5];		// Đếm số lần xuất hiện của 1 câu hỏi
	int* checkAS = new int[5];		// Đếm câu hỏi trả lời sai hay đúng để chỉnh mức độ khó của từ
	Node_wq* P = this->head;						// con tro P cua word question
	Node_wq* P_temp = this->head;				// P_temp để lưu vị trí bắt đầu lấy câu hỏi
	Node_uhw* P_uhw;
	P_uhw = UHW.getUHW();
	int id = 0;
	int size = 0;
	//cout << "Dao vao EXcise" << endl;
	while (P_uhw != NULL)
	{
		//cout << "Da vao " << endl;
		if (id == 5) break;	// Lưu 5 ID của bảng Word Question vào mảng string[5]
		while ((P_uhw != NULL) && (baygio - P_uhw->lastTimeLW > P_uhw->timeCheckBack))	// Kiểm tra từ này đã được học hay chưa?
		{
			//cout << "Da vao While trong" << endl;
			if (id == 5) break;
			//while ((P != NULL) && UHW.searchIDW(P->w_id) == 1)	// Kiểm tra từ này đã được học hay chưa?
			while ((P != NULL) && (P->w_id != P_uhw->w_id))
			{
				//cout << "Da vao While trong1" << endl;
				P = P->next;
				P_temp = P_temp->next;
			}
			//cout << P_uhw->w_id << " = " << P->w_id << endl;
			//cout << "Hoc roi" << endl;
			//P = P->next;
			//P_temp = P_temp->next;
			if (P != NULL)	// Lỡ đã học full từ (Nhưng mà nên xét từ đầu để đỡ tốn time)
			{
				//cout << P_uhw->w_id << " = " << P->w_id << endl;
				ID[id] = P->wq_id;
				WR[id] = P->w_id;
				countID[id] = 0;
				checkAS[id] = 0;
				P = P->next;
				id++;
			}
			//cout << "Da vao While trong2" << endl;
			P_uhw = P_uhw->next;
		}
		if (P_uhw != NULL) P_uhw = P_uhw->next;
	}
	size = id;
	if (size == 0)
	{
		//cout << "Khong co tu de on." << endl;
		mylib.status("Khong co tu de on. (An phim bat ki de quay lai!!!)");
		mylib.gotoxy(0, 30);
		system("pause");
		return;
	}

	int maxAnswer = 0;		// Tổng có 20 câu hỏi
	QS = rand() % size;		// Random từ 0 - > 4 (mỗi lần học chỉ được học 5 từ)
	HisQS = QS;				// Câu hỏi đã đưa ra trước đó.

	while (maxAnswer < size * 4)
	{
		//P = this->head;
		//i = 0;
		//id = 0;
		// [a, b] = a + rand() % (b + 1 - a)
		QS = rand() % size;	// Random lại để khác HisQS
		// khong hop li
		while (QS == HisQS)	// Kiểm tra xem câu hỏi được đưa ra có giống với câu hỏi trước đó hay không?
		{
			if (size * 4 - (maxAnswer + 1) > 4)	// Kiểm tra thử số câu hỏi còn lại có lớn hơn 4 hay không?
			{
				QS = rand() % size;
				//HisQS = QS;
			}
			else break;
		}
		HisQS = QS;
		int i = 0;
		P = P_temp;		// Vị trí bắt đầu lấy câu hỏi
		while (P != NULL && i != QS)	// Lấy câu hỏi theo random
		{
			P = P->next;
			i++;
		}
		if (P == NULL)
		{
			//cout << "Khong cau hoi trong WQ!!!\n";
			mylib.status("Khong cau hoi trong WQ!!!");
			mylib.gotoxy(0, 30);
			system("pause");
			break;
		}
		else
		{
			id = 0;
			//cout << P->wq_id << " <=> " << ID[id] << endl;
			while (P->wq_id != ID[id])		// Tìm vị trí câu hỏi được đưa ra
			{
				//cout << P->wq_id << " != " << ID[id] << endl;
				id++;
			}
			//cout << P->wq_id << " = " << ID[i] << endl;
			if (countID[id] < 4)
			{
				//cout << "Cau thu " << maxAnswer + 1 << ":" << endl;
				if (tmp == 0)
				{
					if (MQ.OutQuestion(P->mq_id) == 1)	// tra loi dung
					{
						EXP += 15;
						mylib.EXP(EXP);
						//cout << "EXP = " << EXP << endl;
					}
					else
					{
						mylib.EXP(EXP);
						checkAS[id]++;
					}
					tmp += 1;	// Để xen kẻ 1 câu hỏi nghe, 1 câu hỏi chọn ĐA
				}
				else
				{
					if (FQ.OutQuestion(P->fq_id) == 1)
					{
						EXP += 15;
						mylib.EXP(EXP);
					}
					else
					{
						mylib.EXP(EXP);
						checkAS[id]++;
					}
					tmp -= 1;
				}
				countID[id]++;
				maxAnswer++;
			}

		}
	}

	/*
	id = 0;
	while (id < size)
	{
		cout << ID[id] << ": " << checkAS[id] << endl;
		id++;
	}
	*/
	US.SetEXP(US.GetEXP() + EXP);	// Cong vao diem kinh nghiem nguoi dung
	PlaySound(MAKEINTRESOURCE(9093), GetModuleHandle(NULL), SND_RESOURCE);	// Am thanh hoan thanh
	mylib.DeleteEXP();
	mylib.status("Da on tap xong!!!");
	// Sau khi hoc xong, luu word ID vao bang use has word
	int WordDiff = 0;
	int timeCheckBack;
	int memoryLV;
	baygio = time(0);	// time hien tai
	for (int i = 0; i < size; i++)
	{
		timeCheckBack = UHW.getTimeCheckBack(WR[i]) * 2;
		memoryLV = UHW.getMemorylevel(WR[i]) + 1;
		if (checkAS[i] > 1)
		{
			WordDiff = 1;
			timeCheckBack -= 2;
		}
		else WordDiff = 0;
		UHW.UpdateHadLearnt(WR[i], memoryLV, baygio / 3600, WordDiff, timeCheckBack);
		//cout << WR[i] << endl;
	}
	//UHW.setFlags(1);
	// Xoa mang phu
	delete[] ID;
	delete[] WR;
	delete[] countID;
	delete[] checkAS;
}

void Linked_WQ::Test(Linked_MQ& MQ, Linked_FQ& FQ, Linked_WORD& WORD, User& US)
{
	vector <string> WordLV1;
	vector <string> WordLV2;
	vector <string> WordLV3;
	vector <string> WordLV4;
	vector <string> WordLV5;
	vector <string> ID;	
	MyLib mylib;
	Node_wq* P = this->head;
	Node_WORD* P_word;
	P_word = WORD.getHeadWord();
	while(P_word != NULL)
	{
		if (P_word->w_level == 1) WordLV1.push_back(P_word->w_id);
		if (P_word->w_level == 2) WordLV2.push_back(P_word->w_id);
		if (P_word->w_level == 3) WordLV3.push_back(P_word->w_id);
		if (P_word->w_level == 4) WordLV4.push_back(P_word->w_id);
		if (P_word->w_level == 5) WordLV5.push_back(P_word->w_id);
		P_word = P_word->next;
	}
	int* countLV = new int[6];	 // dem so cau tra loi dung nhieu nhat o moi level
	for (int i = 1; i <= 5; i++) countLV[i] = 0;	// Khoi tao = 0;
	int maxQS = 0;
	int level;
	int questions;
	int flag = 0;
	int ChoiceQS;
	int EXP = 0;
	level = 1 + rand() % 5; // random tu 1 - 5
	while (maxQS < 20)
	{
		while (level == 1)
		{
			flag = 0;
			questions = rand() % WordLV1.size(); // random tu 0 -> cuoi vector
			for (int i = 0; i < ID.size(); i++)
			{
				if (WordLV1[questions] == ID[i])	// kiem tra tu nay da lay ra hay chua?
				{
					flag = 1;
					break;	// lấy rồi, bỏ qua
				}
			}
			if (flag == 1) continue;
			P = this->head;
			while (P != NULL)
			{
				if (P->w_id == WordLV1[questions]) break;
				P = P->next;
			}
			ChoiceQS = rand() % 2; // random tu 0 -> 1
			if (ChoiceQS == 0)
			{
				if (MQ.OutQuestion(P->mq_id) == 1)
				{
					level += 1;
					countLV[1] += 1;
					EXP += 15;
					mylib.EXP(EXP);
				}
			}
			else
			{
				if (FQ.OutQuestion(P->fq_id) == 1)
				{
					level += 1;
					countLV[1] += 1;
					EXP += 15;
					mylib.EXP(EXP);
				}
			}
			ID.push_back(WordLV1[questions]);	// Lưu vô DS câu hỏi đã lấy
			maxQS++;
			flag = 0;
			if (flag == 0) break;
		}
		if (maxQS >= 20) break;
		// ================
		while (level == 2)
		{
			flag = 0;
			questions = rand() % WordLV2.size(); // random tu 0 -> cuoi vector
			for (int i = 0; i < ID.size(); i++)
			{
				if (WordLV2[questions] == ID[i])	// kiem tra tu nay da lay ra hay chua?
				{
					flag = 1;
					break;	// lấy rồi, bỏ qua
				}
			}
			if (flag == 1) continue;
			P = this->head;
			while (P != NULL)
			{
				if (P->w_id == WordLV2[questions]) break;
				P = P->next;
			}
			ChoiceQS = rand() % 2; // random tu 0 -> 1
			if (ChoiceQS == 0)
			{
				if (MQ.OutQuestion(P->mq_id) == 1)
				{
					level += 1;
					countLV[2] += 1;
					EXP += 15;
					//my
					mylib.EXP(EXP);
				}
				else level -= 1;
				
			}
			else
			{
				if (FQ.OutQuestion(P->fq_id) == 1)
				{
					level += 1;
					countLV[2] += 1;
					EXP += 15;
					mylib.EXP(EXP);
				}
				else level -= 1;
				
			}
			ID.push_back(WordLV2[questions]);	// Lưu vô DS câu hỏi đã lấy
			maxQS++;
			flag = 0;
			if (flag == 0) break;
		}
		if (maxQS >= 20) break;

		// ==========================
		while (level == 3)
		{
			flag = 0;
			questions = rand() % WordLV3.size(); // random tu 0 -> cuoi vector
			for (int i = 0; i < ID.size(); i++)
			{
				if (WordLV3[questions] == ID[i])	// kiem tra tu nay da lay ra hay chua?
				{
					flag = 1;
					break;	// lấy rồi, bỏ qua
				}
			}
			if (flag == 1) continue;
			P = this->head;
			while (P != NULL)
			{
				if (P->w_id == WordLV3[questions]) break;
				P = P->next;
			}
			ChoiceQS = rand() % 2; // random tu 0 -> 1
			if (ChoiceQS == 0)
			{
				if (MQ.OutQuestion(P->mq_id) == 1)
				{
					level += 1;
					countLV[3] += 1;
					EXP += 15;
					mylib.EXP(EXP);
				}
				else level -= 1;

			}
			else
			{
				if (FQ.OutQuestion(P->fq_id) == 1)
				{
					level += 1;
					countLV[3] += 1;
					EXP += 15;
					mylib.EXP(EXP);
				}
				else level -= 1;

			}
			ID.push_back(WordLV1[questions]);	// Lưu vô DS câu hỏi đã lấy
			maxQS++;
			flag = 0;
			if (flag == 0) break;
		}
		if (maxQS >= 20) break;
		// ==============================
		while (level == 4)
		{
			flag = 0;
			questions = rand() % WordLV4.size(); // random tu 0 -> cuoi vector
			for (int i = 0; i < ID.size(); i++)
			{
				if (WordLV4[questions] == ID[i])	// kiem tra tu nay da lay ra hay chua?
				{
					flag = 1;
					break;	// lấy rồi, bỏ qua
				}
			}
			if (flag == 1) continue;
			P = this->head;
			while (P != NULL)
			{
				if (P->w_id == WordLV4[questions]) break;
				P = P->next;
			}
			ChoiceQS = rand() % 2; // random tu 0 -> 1
			if (ChoiceQS == 0)
			{
				if (MQ.OutQuestion(P->mq_id) == 1)
				{
					level += 1;
					countLV[4] += 1;
					EXP += 15;
					mylib.EXP(EXP);
				}
				else level -= 1;

			}
			else
			{
				if (FQ.OutQuestion(P->fq_id) == 1)
				{
					level += 1;
					countLV[4] += 1;
					EXP += 15;
					mylib.EXP(EXP);
				}
				else level -= 1;

			}
			ID.push_back(WordLV4[questions]);	// Lưu vô DS câu hỏi đã lấy
			maxQS++;
			flag = 0;
			if (flag == 0) break;
		}
		if (maxQS >= 20) break;
		// ===================================
		while (level == 5)
		{
			flag = 0;
			questions = rand() % WordLV5.size(); // random tu 0 -> cuoi vector
			for (int i = 0; i < ID.size(); i++)
			{
				if (WordLV5[questions] == ID[i])	// kiem tra tu nay da lay ra hay chua?
				{
					flag = 1;
					break;	// lấy rồi, bỏ qua
				}
			}
			if (flag == 1) continue;
			P = this->head;
			while (P != NULL)
			{
				if (P->w_id == WordLV5[questions]) break;
				P = P->next;
			}
			ChoiceQS = rand() % 2; // random tu 0 -> 1
			if (ChoiceQS == 0)
			{
				if (MQ.OutQuestion(P->mq_id) == 1)
				{
					countLV[5] += 1;
					EXP += 15;
					mylib.EXP(EXP);
				}
				else level -= 1;

			}
			else
			{
				if (FQ.OutQuestion(P->fq_id) == 1)
				{
					countLV[5] += 1;
					EXP += 15;
					mylib.EXP(EXP);
				}
				else level -= 1;

			}
			ID.push_back(WordLV5[questions]);	// Lưu vô DS câu hỏi đã lấy
			maxQS++;
			flag = 0;
			if (flag == 0) break;
		}
	}

	int max = 0;
	int demSoCauTLDung = 0;
	for (int i = 1; i <= 5; i++)
	{
		demSoCauTLDung += countLV[i];
		if (max < countLV[i]) max = countLV[i];
	}

	int levelDuDoan = round(demSoCauTLDung * 0.25);
	int dem = 0;
	
	if (levelDuDoan > 1)
	{
		for (int i = 0; i < 5; i++)
		{
			if (max == 2)
			{
				while (level == 2)
				{
					flag = 0;
					questions = rand() % WordLV2.size(); // random tu 0 -> cuoi vector
					for (int i = 0; i < ID.size(); i++)
					{
						if (WordLV2[questions] == ID[i])	// kiem tra tu nay da lay ra hay chua?
						{
							flag = 1;
							break;	// lấy rồi, bỏ qua
						}
					}
					if (flag == 1) continue;
					P = this->head;
					while (P != NULL)
					{
						if (P->w_id == WordLV2[questions]) break;
						P = P->next;
					}
					if (FQ.OutQuestion(P->fq_id) == 1)
					{
						dem += 1;
						EXP += 15;
						mylib.EXP(EXP);
					}
					ID.push_back(WordLV2[questions]);	// Lưu vô DS câu hỏi đã lấy
					maxQS++;
					flag = 0;
					if (flag == 0) break;
				}
			}
			if (max == 3)
			{
				while (level == 3)
				{
					flag = 0;
					questions = rand() % WordLV3.size(); // random tu 0 -> cuoi vector
					for (int i = 0; i < ID.size(); i++)
					{
						if (WordLV3[questions] == ID[i])	// kiem tra tu nay da lay ra hay chua?
						{
							flag = 1;
							break;	// lấy rồi, bỏ qua
						}
					}
					if (flag == 1) continue;
					P = this->head;
					while (P != NULL)
					{
						if (P->w_id == WordLV3[questions]) break;
						P = P->next;
					}
					if (FQ.OutQuestion(P->fq_id) == 1)
					{
						dem += 1;
						EXP += 15;
						mylib.EXP(EXP);
					}
					ID.push_back(WordLV3[questions]);	// Lưu vô DS câu hỏi đã lấy
					maxQS++;
					flag = 0;
					if (flag == 0) break;
				}
			}
			if (max == 4)
			{
				while (level == 4)
				{
					flag = 0;
					questions = rand() % WordLV4.size(); // random tu 0 -> cuoi vector
					for (int i = 0; i < ID.size(); i++)
					{
						if (WordLV4[questions] == ID[i])	// kiem tra tu nay da lay ra hay chua?
						{
							flag = 1;
							break;	// lấy rồi, bỏ qua
						}
					}
					if (flag == 1) continue;
					P = this->head;
					while (P != NULL)
					{
						if (P->w_id == WordLV4[questions]) break;
						P = P->next;
					}
					if (FQ.OutQuestion(P->fq_id) == 1)
					{
						dem += 1;
						EXP += 15;
						mylib.EXP(EXP);
					}
					ID.push_back(WordLV4[questions]);	// Lưu vô DS câu hỏi đã lấy
					maxQS++;
					flag = 0;
					if (flag == 0) break;
				}
			}
			if (max == 5)
			{
				while (level == 5)
				{
					flag = 0;
					questions = rand() % WordLV5.size(); // random tu 0 -> cuoi vector
					for (int i = 0; i < ID.size(); i++)
					{
						if (WordLV5[questions] == ID[i])	// kiem tra tu nay da lay ra hay chua?
						{
							flag = 1;
							break;	// lấy rồi, bỏ qua
						}
					}
					if (flag == 1) continue;
					P = this->head;
					while (P != NULL)
					{
						if (P->w_id == WordLV5[questions]) break;
						P = P->next;
					}
					if (FQ.OutQuestion(P->fq_id) == 1)
					{
						dem += 1;
						EXP += 15;
						mylib.EXP(EXP);
					}
					ID.push_back(WordLV5[questions]);	// Lưu vô DS câu hỏi đã lấy
					maxQS++;
					flag = 0;
					if (flag == 0) break;
				}
			}

		}
	}
	US.SetEXP(US.GetEXP() + EXP);
	mylib.DeleteEXP();
	string s1 = "L0001";
	string s2 = "L0002";
	string s3 = "L0003";
	string s4 = "L0004";
	string s5 = "L0005";
	if (dem > 3)
	{
		if (max == 2)	US.SetLevel(s2);
		if (max == 3)	US.SetLevel(s3);
		if (max == 4)	US.SetLevel(s4);
		if (max == 5)	US.SetLevel(s5);
	}
	else
	{
		if (max == 1) US.SetLevel(s1);
		else
		{
			max = max - 1;
			if (max == 1)	US.SetLevel(s1);
			if (max == 2)	US.SetLevel(s2);
			if (max == 3)	US.SetLevel(s3);
			if (max == 4)	US.SetLevel(s4);
			if (max == 5)	US.SetLevel(s5);
		}
	}
	PlaySound(TEXT("./sound/9093finish.wav"), NULL, SND_ASYNC);	// Am thanh hoan thanh
	mylib.status("Chuc mung ban da hoan thanh bai kiem tra!!!");
	mylib.gotoxy(0, 30);
	system("pause");
	delete[] countLV;
}

void Linked_WQ::LearnWordLevel(Linked_MQ& MQ, Linked_FQ& FQ, Linked_UHW& UHW, Linked_WORD& WORD, User& US, string Level)
{
	MyLib mylib;
	int level;
	if (Level == "L0001") level = 1;
	if (Level == "L0002") level = 2;
	if (Level == "L0003") level = 3;
	if (Level == "L0004") level = 4;
	if (Level == "L0005") level = 5;
	vector <string> WordLV1;
	vector <string> WordLV2;
	vector <string> WordLV3;
	vector <string> WordLV4;
	vector <string> WordLV5;
	Node_WORD* P_word;
	P_word = WORD.getHeadWord();
	while (P_word != NULL)
	{
		if (P_word->w_level == 1) WordLV1.push_back(P_word->w_id);
		if (P_word->w_level == 2) WordLV2.push_back(P_word->w_id);
		if (P_word->w_level == 3) WordLV3.push_back(P_word->w_id);
		if (P_word->w_level == 4) WordLV4.push_back(P_word->w_id);
		if (P_word->w_level == 5) WordLV5.push_back(P_word->w_id);
		P_word = P_word->next;
	}
	int EXP = 0; // Diem kinh nghiem
	int i;
	int QS;
	int tmp = 0;
	int HisQS;
	string* ID = new string[5];		// Lưu danh sách câu hỏi được lấy
	string* WR = new string[5];		// Lưu danh sách từ đã học
	int* countID = new int[5];		// Đếm số lần xuất hiện của 1 câu hỏi
	int* checkAS = new int[5];		// Đếm câu hỏi trả lời sai hay đúng để chỉnh mức độ khó của từ
	Node_wq* P = this->head;						// con tro P cua word question
	Node_wq* P_temp = this->head;				// P_temp để lưu vị trí bắt đầu lấy câu hỏi

	int id;
	int size;
	if (level == 1)
	{
		int i = 0;
		id = 0;
		size = 0;
		while (P != NULL)
		{
			if (id == 5) break;	// Lưu 5 ID của bảng Word Question vào mảng string[5]
			while ((i < WordLV1.size()) && UHW.searchIDW(WordLV1[i]) == 1)	// Kiểm tra từ này đã được học hay chưa?
			{
				//cout << WordLV1.size() << " : " << i << endl;
				i++;
			}
	
			if (i == WordLV1.size())	break;
			
			while (P != NULL)
			{
				if (P->w_id == WordLV1[i]) break;
				P = P->next;
				P_temp = P_temp->next;
			}
			if (P != NULL)	// Lỡ đã học full từ (Nhưng mà nên xét từ đầu để đỡ tốn time)
			{
				ID[id] = P->wq_id;
				WR[id] = P->w_id;
				countID[id] = 0;
				checkAS[id] = 0;
				P = P->next;
				id++;
				i++;
			}

		}
	}
	
	if (level == 2)
	{
		int i = 0;
		id = 0;
		size = 0;
		while (P != NULL)
		{
			if (id == 5) break;	// Lưu 5 ID của bảng Word Question vào mảng string[5]
			while ((i < WordLV2.size()) && UHW.searchIDW(WordLV2[i]) == 1)	// Kiểm tra từ này đã được học hay chưa?
			{
				i++;
			}

			if (i == WordLV2.size())	break;

			while (P != NULL)
			{
				if (P->w_id == WordLV2[i]) break;
				P = P->next;
				P_temp = P_temp->next;
			}
			if (P != NULL)	// Lỡ đã học full từ (Nhưng mà nên xét từ đầu để đỡ tốn time)
			{
				ID[id] = P->wq_id;
				WR[id] = P->w_id;
				countID[id] = 0;
				checkAS[id] = 0;
				P = P->next;
				id++;
				i++;
			}

		}
	}

	if (level == 3)
	{
		int i = 0;
		id = 0;
		size = 0;
		while (P != NULL)
		{
			if (id == 5) break;	// Lưu 5 ID của bảng Word Question vào mảng string[5]
			while ((i < WordLV3.size()) && UHW.searchIDW(WordLV3[i]) == 1)	// Kiểm tra từ này đã được học hay chưa?
			{
				i++;

			}

			if (i == WordLV3.size())	break;
			while (P != NULL)
			{
				if (P->w_id == WordLV3[i]) break;
				P = P->next;
				P_temp = P_temp->next;
			}
			if (P != NULL)	// Lỡ đã học full từ (Nhưng mà nên xét từ đầu để đỡ tốn time)
			{
				ID[id] = P->wq_id;
				WR[id] = P->w_id;
				countID[id] = 0;
				checkAS[id] = 0;
				P = P->next;
				id++;
				i++;
			}

		}
	}

	if (level == 4)
	{
		int i = 0;
		id = 0;
		size = 0;
		while (P != NULL)
		{
			if (id == 5) break;	// Lưu 5 ID của bảng Word Question vào mảng string[5]
			while ((i < WordLV4.size()) && UHW.searchIDW(WordLV4[i]) == 1)	// Kiểm tra từ này đã được học hay chưa?
			{
				i++;
			}

			if (i == WordLV4.size())	break;

			while (P != NULL)
			{
				if (P->w_id == WordLV4[i]) break;
				P = P->next;
				P_temp = P_temp->next;
			}
			if (P != NULL)	// Lỡ đã học full từ (Nhưng mà nên xét từ đầu để đỡ tốn time)
			{
				ID[id] = P->wq_id;
				WR[id] = P->w_id;
				countID[id] = 0;
				checkAS[id] = 0;
				P = P->next;
				id++;
				i++;
			}

		}
	}

	if (level == 5)
	{
		int i = 0;
		id = 0;
		size = 0;
		while (P != NULL)
		{
			if (id == 5) break;	// Lưu 5 ID của bảng Word Question vào mảng string[5]
			while ((i < WordLV5.size()) && UHW.searchIDW(WordLV5[i]) == 1)	// Kiểm tra từ này đã được học hay chưa?
			{
				//cout << "Hoc roi" << endl;
				i++;

			}

			if (i == WordLV5.size()) break;

			while (P != NULL)
			{
				if (P->w_id == WordLV5[i]) break;
				P = P->next;
				P_temp = P_temp->next;
			}
			if (P != NULL)	// Lỡ đã học full từ (Nhưng mà nên xét từ đầu để đỡ tốn time)
			{
				ID[id] = P->wq_id;
				WR[id] = P->w_id;
				countID[id] = 0;
				checkAS[id] = 0;
				P = P->next;
				id++;
				i++;
			}
		}
	}

	size = id;
	if (size == 0)
	{
		mylib.status("Ban da hoc het tu o level nay!");
		mylib.gotoxy(0, 30);
		system("pause");
		mylib.status("(Bam Phim bat ki de quay lai!!!)");
		if (US.GetLevel() == "L0001")
		{
			US.SetLevel("L0002");
			mylib.status("Chuc mung ban da qua level 2!");
			return;
		}
		if (US.GetLevel() == "L0002")
		{
			US.SetLevel("L0003");
			mylib.status("Chuc mung ban da qua level 3!");
			return;
		}
		if (US.GetLevel() == "L0003")
		{
			US.SetLevel("L0004");
			mylib.status("Chuc mung ban da qua level 4!");
			return;
		}
		if (US.GetLevel() == "L0004")
		{
			US.SetLevel("L0005");
			mylib.status("Chuc mung ban da qua level 5!");
			return;
		}
		if (US.GetLevel() == "L0005")
		{
			mylib.status("Chuc mung ban da hoan thanh khoa hoc (*_*) ");
		}
		return;
	}
	
	int maxAnswer = 0;		// Tổng có 20 câu hỏi
	QS = rand() % size;		// Random từ 0 - > 4 (mỗi lần học chỉ được học 5 từ)
	HisQS = QS;				// Câu hỏi đã đưa ra trước đó.

	while (maxAnswer < size*4)
	{
		// [a, b] = a + rand() % (b + 1 - a)
		QS = rand() % size;	// Random lại để khác HisQS
		while (QS == HisQS)	// Kiểm tra xem câu hỏi được đưa ra có giống với câu hỏi trước đó hay không?
		{
			if (size*4 - (maxAnswer + 1) > 4)	// Kiểm tra thử số câu hỏi còn lại có lớn hơn 4 hay không?
			{
				QS = rand() % size;
			}
			else break;
		}
		HisQS = QS;
		int i = 0;	
		P = P_temp;		// Vị trí bắt đầu lấy câu hỏi
		while (P != NULL && i != QS)	// Lấy câu hỏi theo random
		{
			P = P->next;
			i++;
		}
		if (P == NULL)
		{
			mylib.status("Khong cau hoi trong WQ!!!");
			break;
		}
		else
		{
			id = 0;
			while (P->wq_id != ID[id])		// Tìm vị trí câu hỏi được đưa ra
			{
				id++;
			}
			
			if (countID[id] < 4)
			{
				string str1;
				ostringstream convert1;
				convert1 << maxAnswer + 1;
				str1 = "Cau thu " + convert1.str();
				mylib.status(str1);
				//wcout << L"Cau thu " << maxAnswer + 1 << ":" << endl;
				if (tmp == 0)
				{
					if (MQ.OutQuestion(P->mq_id) == 1)	// tra loi dung
					{
						EXP += 15;
						//wcout << L"EXP = " << EXP << endl;
						mylib.EXP(EXP);
					}
					else
					{
						//wcout << L"EXP = " << EXP << endl;
						mylib.EXP(EXP);
						checkAS[id]++;
					}
					tmp += 1;	// Để xen kẻ 1 câu hỏi nghe, 1 câu hỏi chọn ĐA
				}
				else
				{
					if (FQ.OutQuestion(P->fq_id) == 1)
					{
						EXP += 15;
						//wcout << L"EXP = " << EXP << endl;
						mylib.EXP(EXP);
					}
					else
					{
						//wcout << L"EXP = " << EXP << endl;
						mylib.EXP(EXP);
						checkAS[id]++;
					}
					tmp -= 1;
				}
				countID[id]++;
				maxAnswer++;
			}	
		}	
	}

	US.SetEXP(US.GetEXP() + EXP);	// Cong vao diem kinh nghiem nguoi dung
	PlaySound(TEXT("./sound/9093finish.wav"), NULL, SND_ASYNC);	// Am thanh hoan thanh
	mylib.DeleteEXP();
	mylib.status("Da hoc xong!!!");
	// Sau khi hoc xong, luu word ID vao bang use has word
	int WordDiff = 0;
	int timeCheckBack = 5;
	time_t baygio = time(0);	// time hien tai
	for (int i = 0; i < size; i++)
	{
		if (checkAS[i] > 2)
		{
			WordDiff = 1;
			timeCheckBack -= 2;
		}
		else WordDiff = 0;
		UHW.AddWordHadLearnt(WR[i], 1, baygio/3600, WordDiff, timeCheckBack);
	}
	UHW.setFlags(1);
	// Xoa mang phu
	delete[] ID;
	delete[] WR;
	delete[] countID;
	delete[] checkAS;
	
}