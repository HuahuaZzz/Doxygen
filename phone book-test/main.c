#include <stdio.h>
#include <string.h>

#define MAXNUM 256
#define MEMBER_FILE "member.log"
#define BOOK_FILE "book.log"
#define DATA_FILE "data.log"

//防呆判斷數
#include<ctype.h>
#define CHECKNUMBER 8
#define CHECKENGLISH 3
#define PHOTONUM 10



struct MEMBER{ //member date struct
    int id; //索引
    char member_name[10]; //名子
    char address_name[50]; //地址
    char accout_name[20]; //帳號
    char password_name[20]; //密碼
    char phone_name[20]; //電話
    char email_name[30]; //電子信箱
    int man; // 1:man 0:woman
} members[MAXNUM];

struct BOOK{ //book date
    int book_id; //索引
    char book_name[80]; //名子
    char club_name[80]; //類別
    int level; //等級
    char date_name[10]; //資料
    int state_book; //是否已借
}books[MAXNUM];

struct DATA{  //borrowing book date
    int id;
    char member_name[10];
    int book_num;
    int book_id[6];
}data[MAXNUM];

void initMember(struct MEMBER members[]) // initialization struct members
{
    int i;
    for (i = 0 ; i < 256 ; i++)
    {
        members[i].id = -1 ;
    }
}


void initBooks(struct BOOK books[]) // initialization struct books
{
    int i;
    for (i = 0 ; i < 256 ; i++)
    {
        books[i].book_id = -1 ;
    }
}

void initData(struct DATA data[]) // initialization struct data
{
    int i;
    for (i = 0 ; i < 256 ; i++)
    {
        data[i].id = -1 ;
    }
}


// 載入會員資料
void loadMember(FILE * fp , struct MEMBER members[]) //load member data
{

    int i;
    i = 1;
    while (fscanf(fp,"%d",&members[i].id) != EOF )
    {
        fscanf(fp,"%s",members[i].member_name);
        fscanf(fp,"%s",members[i].address_name);
        fscanf(fp,"%s",members[i].accout_name);
        fscanf(fp,"%s",members[i].password_name);
        fscanf(fp,"%s",members[i].phone_name);
        fscanf(fp,"%s",members[i].email_name);
        fscanf(fp,"%d",&members[i].man);
        i=i+1;
    }
}

// 載入書籍資料
void loadBooks(FILE * fp,struct BOOK books[]) // load book data
{
    int i;
    i = 1;
    while ( fscanf(fp, "%d", &books[i].book_id) != EOF)
    {
        fscanf(fp, "%s", books[i].book_name);
        fscanf(fp, "%s", books[i].club_name);
        fscanf(fp, "%d", &books[i].level);
        fscanf(fp, "%s", books[i].date_name);
        fscanf(fp, "%d", &books[i].state_book);
        i = i + 1;
    }
}

void loadData(FILE * fp , struct DATA data[]) //
{

    int i,j;
    i = 1;
    while( fscanf(fp,"%d",&data[i].id) != EOF )
    {
        fscanf(fp, "%d", &data[i].id);
        fscanf(fp, "%s", data[i].member_name);
        fscanf(fp, "%d", &data[i].book_num);
        for (j=1 ; j <= data[i].book_num; j++) //判定借了幾本書 要執行幾次
        {
            fscanf(fp,"%d",&data[i].book_id[j]); // 抓取 書ID
        }
        i = i + 1 ;
    }
}

// 根據書籍ID搜尋該書籍的資料位置
int searchBooks(struct BOOK books[] , int book_id)
{
    int i, index ;
    index = -1 ;
    for(i = 1 ; i <256 ; i++)
    {
        if(books[i].book_id == book_id)
        {
            index = i ;
            return index ;
        }
    }
    return index;
}

// 搜尋會員的資料位置
int searchMember(struct MEMBER members[] , int id)
{
    int i, index ;
    index = -1 ;
    for(i = 1 ; i <256 ; i++)
    {
        if(members[i].id == id)
        {
            index = i ;
            return index ;
        }
    }
    return index;
}

//顯示會員資料
void showMember(struct MEMBER members[])
{
    int i , counter ;
    counter = 0 ; //計算次數
    printf("已加入的會員 => \n ");
    for (i = 1 ; i <= 256 ; i++)
    {
        if(members[i].id == -1) {break;}
        printf("\n");
        printf("-----------------第 %d 筆----------------" , i);
        printf("\n");
        printf("會員編號: %d ",members[i].id);
        printf("\n");
        printf("會員名稱: %s ", members[i].member_name);
        printf("\n");
        printf("會員地址: %s ", members[i].address_name);
        printf("\n");
        printf("會員帳號: %s ", members[i].accout_name);
        printf("\n");
        printf("會員密碼: %s ", members[i].password_name);
        printf("\n");
        printf("會員電話: %s ", members[i].phone_name);
        printf("\n");
        printf("會員電子信箱: %s ", members[i].email_name);
        printf("\n");
        printf("會員性別: %d (0: man 1: woman)", members[i].man);
        printf("\n");
        printf("-----------------------------------------");
        printf("\n");
        counter = counter + 1;
    }
    printf("共%d筆資料\n", counter);
}

// 顯示書籍資料
void showBooks(struct BOOK books[])
{
    int i, counter;
    counter = 0;
    printf("書庫資料: => \n");
    for (i = 1; i <= 256; i++) {
        if (books[i].book_id == -1) {
            break;
        }
        printf("\n");
        printf("-----------------第 %d 筆----------------" , i);
        printf("\n");
        printf("書籍編號: %d ", books[i].book_id);
        printf("\n");
        printf("書籍名稱: %s ", books[i].book_name);
        printf("\n");
        printf("出版社名稱: %s ", books[i].club_name);
        printf("\n");
        printf("書籍分級: %d ", books[i].level);
        printf("\n");
        printf("書籍進書日期: %s ", books[i].date_name);
        printf("\n");
        printf("書籍以被借出數量: %d ", books[i].state_book);
        printf("\n");
        printf("-----------------------------------------");
        printf("\n");
        counter = counter + 1;
    }
    printf("共%d筆資料\n", counter);
}

// 顯示借書歸還資料
void showData(struct DATA data[], int id, int index)
{
    int i;
    int county = 0;
    printf("您已借下列書籍:\n");
    for (i = 1; i <= data[index].book_num; i++) {
        printf("第%d本編號是: %d ", i , data[index].book_id[i]);
        county = county +1 ;
    }
    printf("\n");
    printf("共有 %d 本 \n",county);
}


// 新增書籍資料
int addBooks(struct BOOK books[])
{
    int i;
    int index;
    int book_id;
    for (i = 1; i < 256; i++) {
        if (books[i].book_id == -1) {
            printf("\t");
            printf("輸入書籍編號:");
            scanf("%d", &book_id);
            printf("\t");
            index = searchBooks(books, book_id);
            if (index != -1) {
                return 2;
            }
            books[i].book_id = book_id;
            printf("輸入書名:");
            scanf("%s", books[i].book_name);
            printf("\t");
            printf("輸入出版社名稱:");
            scanf("%s", books[i].club_name);
            printf("\t");
            printf("輸入書的分級:");
            scanf("%d", &books[i].level);
            printf("\t");
            printf("輸入進書日期: ");
            scanf("%s", books[i].date_name);
            printf("\t");
            books[i].state_book = 0;
            printf("\t");
            return 1;
        }
    }
}

// 根據會員ID搜尋借閱紀錄位置
int searchData(struct DATA data[], int id)
{
    int i, index;
    index = -1;
    for (i = 1; i < 256; i++) {
        if (data[i].id == id) {
            index = i;
            return index;
        }
    }
    return index;
}

// 刪除書籍
int subBooks(struct BOOK books[], int book_id)
{
    int i , j;
    for (i = 1; i <= 256; i++) {
        if (books[i].book_id == book_id) {
            if (books[i].state_book == 1) {
                return 3;
            }
            books[i].book_id = -1;
            return 1;
        }
    }
    return 2;
}


// 新增會員
int addMember(struct MEMBER members[],struct DATA data[])
{
    int i , j ;
    int index ;
    int id ;
    for( i = 1 ; i < 256 ; i ++)
    {
        if(members[i].id == -1)
        {
            printf("\t");
            printf("輸入會員編號:");
            scanf("%d", &id);
            printf("\t");
            index = searchMember(members , id);
            if (index != -1)
            {
                return 2 ;
            }
            members[i].id = id ;
            printf("輸入姓名:");
            scanf("%s", members[i].member_name);
            printf("\t");
            printf("輸入地址:");
            scanf("%s", members[i].address_name);
            printf("\t");
            printf("輸入帳號:");
            scanf("%s", members[i].accout_name);
            printf("\t");
            printf("輸入密碼:");
            scanf("%s", members[i].password_name);
            printf("\t");
            printf("輸入電話:");
            scanf("%s", members[i].phone_name);
            printf("\t");
            printf("輸入電子信箱:");
            scanf("%s", members[i].email_name);
            printf("\t");
            printf("輸入性別 0:woman 1: man :");
            scanf("%d",& members[i].man);
            printf("\t");

            for (j = 1; j <= 256; j++) {
                if (data[j].id == -1) {
                    data[j].id = members[i].id;
                    strcpy(data[j].member_name, members[i].member_name);
                    data[j].book_num = 0;
                    return 1;
                }
            }
        }
    }
}

// 刪除會員
int subMember(struct MEMBER members[], struct DATA data[], int id)
{
    int i, j;
    for (i = 1; i < 256; i++) {
        if (members[i].id == id) {
            members[i].id = -1;
            for (j = 1; j < 256; j++) {
                if (data[j].id == id) {
                    data[j].id = -1;
                }
            }
            return 1;
        }
    }
    return 2;
}


// 會員借書
int addData(struct DATA data[], struct BOOK books[], int book_id, int index)
{
    int i;
    int index1;
    index1 = searchBooks(books, book_id);
    if (books[index1].state_book == 1) {
        return 5; //此書已被借走
    }
    if (data[index].book_num == 5) {
        return 4; //您的借書額度已滿
    }
    if (book_id >= 1 && book_id < 256) {
        for (i = 1; i <= data[index].book_num; i++) {
            if (data[index].book_id[i] == book_id) {
                return 3;
            }
        }
        data[index].book_id[i] = book_id;
        data[index].book_num = data[index].book_num + 1;
        books[index1].state_book = 1;
        return 1; //借書完成
    }
    return 2; //借書完成
}

// 會員還書
int subdata(struct DATA data[], struct BOOK books[], int book_id, int index)
{
    int i;
    int index1;
    int j;
    index1 = searchBooks(books, book_id);
    if (book_id >= 1 && book_id < 256) {
        for (i = 1; i <= data[index].book_num; i++) {
            if (data[index].book_id[i] == book_id) {
                j = data[index].book_id[data[index].book_num];
                data[index].book_id[data[index].book_num] = book_id;
                data[index].book_id[i] = j;
                data[index].book_num = data[index].book_num - 1;
                books[index1].state_book = 0;
                return 1;  //還書完成
            }
        }
        return 3; //未借此書
    }
    return 2; //查無此書
}

// 儲存會員資料
void saveMember(FILE * fp, struct MEMBER members[])
{
    int i;
    for (i = 1; i < 256; i++) {
        if (members[i].id != -1) {
            fprintf(fp, "%d", members[i].id);
            fprintf(fp, "\t");
            fprintf(fp, "%s", members[i].member_name);
            fprintf(fp, "\t");
            fprintf(fp, "%s", members[i].address_name);
            fprintf(fp, "\t");
            fprintf(fp, "%s", members[i].accout_name);
            fprintf(fp, "\t");
            fprintf(fp, "%s", members[i].password_name);
            fprintf(fp, "\t");
            fprintf(fp, "%s", members[i].phone_name);
            fprintf(fp, "\t");
            fprintf(fp, "%s", members[i].email_name);
            fprintf(fp, "\t");
            fprintf(fp, "%d", members[i].man);
            fprintf(fp, "\n");
        }
    }
}

// 儲存書籍資料
void saveBooks(FILE * fp, struct BOOK books[])
{
    int i;
    for (i = 1; i < 256; i++) {
        if (books[i].book_id != -1) {
            fprintf(fp, "%d", books[i].book_id);
            fprintf(fp, "\t");
            fprintf(fp, "%s", books[i].book_name);
            fprintf(fp, "\t");
            fprintf(fp, "%s", books[i].club_name);
            fprintf(fp, "\t");
            fprintf(fp, "%d", books[i].level);
            fprintf(fp, "\t");
            fprintf(fp, "%s", books[i].date_name);
            fprintf(fp, "\t");
            fprintf(fp, "%d", books[i].state_book);
            fprintf(fp, "\t");
            fprintf(fp, "\n");
        }
    }
}

// 儲存借還書結果
void saveData(FILE * fp, struct DATA data[])
{
    int i, j;
    for (i = 1; i < 256; i++) {
        if (data[i].id != -1) {
            fprintf(fp, "%d", data[i].id);
            fprintf(fp, "\t");
            fprintf(fp, "%s", data[i].member_name);
            fprintf(fp, "\t");
            fprintf(fp, "%d", data[i].book_num);
            fprintf(fp, "\t");
            for (j = 1; j <= data[i].book_num; j++) {
                fprintf(fp, "%d", data[i].book_id[j]);
                fprintf(fp, "\t");
            }
            fprintf(fp, "\n");
        }
    }
}



int main()
{
FILE *fp;

    char user;
    char choice;
    int id;
    int book_id;
    int index;
    int result;

    initMember(members);
    initBooks(books);
    initData(data);

    // 載入會員資料
    fp = fopen(MEMBER_FILE, "r");
    loadMember(fp, members);
    fclose(fp);
    // 載入書籍資料
    fp = fopen(BOOK_FILE, "r");
    loadBooks(fp, books);
    fclose(fp);
    // 載入借書歸還資料
    fp = fopen(DATA_FILE, "r");
    loadData(fp, data);
    fclose(fp);

    printf("┌────────────────────────┐\n\
│                                                │\n\
│【書籍租借系統】                                │\n\
│讓使用者能藉由此系統進行借還書,顯示及管理等動作 │\n\
└────────────────────────┘\n");

    while (1) {
        printf("\n請選擇身分 (A.管理員 B.會員 C.加入新會員 D.結束) >");
        fflush(stdin);
        scanf("%c", &user);
        switch (user) {
        case 'A':
        case 'a':

            while (1) {
                fp = fopen(BOOK_FILE, "w");
                saveBooks(fp, books);
                fclose(fp);
                fp = fopen(MEMBER_FILE, "w");
                saveMember(fp, members);
                fclose(fp);
                fp = fopen(DATA_FILE, "w");
                saveData(fp, data);
                fclose(fp);
                printf("\n");
                printf("請輸入指令\n");
                printf("\n1.新增書籍 2.刪除書籍 3.增加會員 4.刪除會員\n\
5.顯示書籍 6.顯示會員 7.結束>");
                fflush(stdin);
                scanf("%c", &choice);
                switch (choice) {
                case '1':
                    result = addBooks(books);
                    if (result == 1) {
                        printf("新增書籍完成\n");
                    }
                    if (result == 2) {
                        printf("已有此書\n");
                    }
                    fp = fopen(BOOK_FILE, "w");
                    saveBooks(fp, books);
                    fclose(fp);

                    break;

                case '2':
                    printf("輸入欲刪除的書籍編號:");
                    scanf("%d", &book_id);
                    result = subBooks(books, book_id);
                    if (result == 1) {
                        printf("刪除書籍完成\n");
                    }
                    if (result == 2) {
                        printf("查無此書\n");
                    }
                    if (result == 3) {
                        printf("此書出借中,無法刪除\n");
                    }
                    break;

                case '3':
                    result = addMember(members, data);
                    if (result == 1) {
                        printf("新增會員完成\n");
                    }
                    if (result == 2)
                        printf("已有此會員\n");
                    break;

                case '4':
                    printf("請輸入欲刪除的會員編號:");
                    scanf("%d", &id);
                    result = subMember(members, data, id);
                    if (result == 1)
                        printf("刪除會員完成\n");
                    if (result == 2)
                        printf("查無此會員\n");
                    break;

                case '5':
                    showBooks(books);
                    break;

                case '6':
                    showMember(members);
                    break;

                case '7':
                    exit(1);

                }
            }
            break;

        case 'B':
        case 'b':
            printf("請輸入會員編號:");
            scanf("\r%d", &id);
            index = searchData(data, id);
            if (index == -1) {
                printf("無此會員或是輸入錯誤\n");
                exit(1);
            }

            while (1) {
                fp = fopen(BOOK_FILE, "w");
                saveBooks(fp, books);
                fclose(fp);

                showBooks(books);
                showData(data, id, index);
                printf("請輸入指令\n");
                printf("1.借書 2.還書 3.顯示借還書資料 4.結束>");
                fflush(stdin);
                scanf("\r%c", &choice);
                switch (choice) {
                case '1':
                    printf("請輸入欲借書本代號, -1結束借書> ");
                    scanf("%d", &book_id);
                    if (book_id == -1)  // 如果借書代號為-1
                    {
                        printf("借書結束\n");
                        printf("\n");
                        break;  // 離開借書的迴圈
                    }
                    result = addData(data, books, book_id, index);

                    switch (result) {
                    case 1:
                        printf("借書完成\n");
                        break;
                    case 2:
                        printf("借書完成\n");
                        break;
                    case 3:
                        printf("您已借此書\n");
                        break;
                    case 4:
                        printf("您的借書額度已滿\n");
                        break;
                    case 5:
                        printf("此書已被借走\n");
                        break;
                    }

                    fp = fopen(DATA_FILE, "w");
                    saveData(fp, data);
                    fclose(fp);
                    break;

                case '2':
                    if (data[index].book_num == 0) {
                        printf("未借任何書籍\n");
                        break;
                    }
                    printf("請輸入欲還書本代號, -1結束還書> ");
                    scanf("%d", &book_id);
                    if (book_id == -1)  // 如果借書代號為-1
                    {
                        printf("借書結束\n");
                        printf("\n");
                        break;  // 離開借書的迴圈
                    }
                    result = subdata(data, books, book_id, index);
                    if (result == 1) {
                        printf("還書完成\n");
                    }
                    if (result == 2) {
                        printf("查無此書\n");
                    }
                    if (result == 3) {
                        printf("未借此書\n");
                    }
                    fp = fopen(DATA_FILE, "w");
                    saveData(fp, data);
                    fclose(fp);
                    break;

                case '3':
                    showData(data, id, index);
                    break;

                case '4':
                    exit(1);
                }
            }
            break;

        case 'C':
        case 'c':

            result = addMember(members, data);
            if (result == 1) {
                printf("新增會員完成\n");
            }
            if (result == 2) {
                printf("已有此會員\n");
            }
            break;

        case 'D':
        case 'd':
            exit(1);
        }

        // 儲存會員資料
        fp = fopen(MEMBER_FILE, "w");
        saveMember(fp, members);
        fclose(fp);
        // 儲存書籍資料
        fp = fopen(BOOK_FILE, "w");
        saveBooks(fp, books);
        fclose(fp);
        // 儲存借還書紀錄
        fp = fopen(DATA_FILE, "w");
        saveData(fp, data);
        fclose(fp);
    }
}



//字串防呆
int Checked_arrary_input(char InputText[],int CheckType)
{
    int Loop_i,Input_array_count=0,CheckAnswer=0,InputEng=0,InputNum=0,InputSpace=0,InputEmail=0,InputError=0;
    char Checked_Char;
    Input_array_count = strlen(InputText);
    if(Input_array_count >0)
    {
        for(Loop_i=0;Loop_i<Input_array_count;Loop_i++)
        {
            Checked_Char=InputText[Loop_i];
            if(isalpha(Checked_Char))
            {
                InputEng++;
            }
            else if(isdigit(Checked_Char))
            {
                InputNum++;
            }
            else if(isspace(Checked_Char))
            {
                InputSpace++;
            }
            else if(Checked_Char==64)
            {
                InputEmail++;
            }
            else
            {
                InputError++;
            }
        }
        switch(CheckType)
        {
            case 1:
                //名子判斷
                if(InputEng<CHECKENGLISH || InputNum<CHECKNUMBER || InputEmail>0 ||InputError>0 )
                {
                    return CheckAnswer =-1;
                }
            break;

            case 2:
                //地址判斷
                if(InputEmail>0 || InputError>0)
                {
                    return CheckAnswer =-2;
                }
            break;

            case 3:
                //帳號判斷
                if(InputEng<CHECKENGLISH || InputNum<CHECKNUMBER || InputEmail>0 ||InputError>0)
                {
                    return CheckAnswer =-3;
                }
            break;

            case 4:
                //密碼判斷
                if(InputEng<CHECKENGLISH || InputNum<CHECKNUMBER || InputEmail>0 ||InputError>0 )
                {
                    return CheckAnswer =-4;
                }
            break;

            case 5:
                //電話判斷
                if(InputNum!=PHOTONUM || InputEmail>0 ||InputError>0)
                {
                    return CheckAnswer =-5;
                }
            break;

            case 6:
                //電子信箱判斷
                if(InputEmail != 1)
                {
                    return CheckAnswer =-6;
                }
            break;
        }
    }
    return CheckAnswer;
}







