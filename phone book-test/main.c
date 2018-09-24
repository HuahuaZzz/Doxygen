#include <stdio.h>
#include <string.h>
#include <time.h>
#define MAXNUM 256
#define MEMBER_FILE "member.log"
#define BOOK_FILE "book.log"
#define DATA_FILE "data.log"

//防呆判斷數
#include<ctype.h>
#define CHECKNUMBER 8
#define CHECKENGLISH 3
#define PHOTONUM 10



struct MEMBER { //member date struct
    int id; //索引
    char member_name[10]; //名子
    char address_name[50]; //地址
    char accout_name[20]; //帳號
    char password_name[20]; //密碼
    char phone_name[20]; //電話
    char email_name[30]; //電子信箱
    int man; // 1:man 0:woman
    int power; // 權限 0 為一般 1為管理員
} members[MAXNUM];

struct BOOK { //book date
    int book_id; //索引
    char book_name[80]; //名子
    char club_name[80]; //類別
    int level; //等級
    char date_name[10]; //資料
    int state_book; //是否已借
    char BorrowDay[10];
    char DeadLineDay[10];
} books[MAXNUM];

struct DATA { //borrowing book date
    int id;
    char member_name[10];
    int book_num;
    int book_id[6];
} data[MAXNUM];

void initMember(struct MEMBER members[]) // initialization struct members
{
    int i;
    for (i = 0 ; i < 256 ; i++)
    {
        members[i].id = -1 ;
        members[i].power = 0 ;
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
    while (fscanf(fp, "%d", &members[i].id) != EOF )
    {
        fscanf(fp, "%s", members[i].member_name);
        fscanf(fp, "%s", members[i].address_name);
        fscanf(fp, "%s", members[i].accout_name);
        fscanf(fp, "%s", members[i].password_name);
        fscanf(fp, "%s", members[i].phone_name);
        fscanf(fp, "%s", members[i].email_name);
        fscanf(fp, "%d", &members[i].man);
        fscanf(fp, "%d", &members[i].power);
        i = i + 1;
    }
}

// 載入書籍資料
void loadBooks(FILE * fp, struct BOOK books[]) // load book data
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
        fscanf(fp, "%s", books[i].BorrowDay);
        fscanf(fp, "%s", books[i].DeadLineDay);
        i = i + 1;
    }
}

void loadData(FILE * fp , struct DATA data[]) //
{

    int i, j;
    i = 1;
    while ( fscanf(fp, "%d", &data[i].id) != EOF )
    {
        fscanf(fp, "%d", &data[i].id);
        fscanf(fp, "%s", data[i].member_name);
        fscanf(fp, "%d", &data[i].book_num);
        for (j = 1 ; j <= data[i].book_num; j++) //判定借了幾本書 要執行幾次
        {
            fscanf(fp, "%d", &data[i].book_id[j]); // 抓取 書ID
        }
        i = i + 1 ;
    }
}

// 根據書籍ID搜尋該書籍的資料位置
int searchBooks(struct BOOK books[] , int book_id)
{
    int i, index ;
    index = -1 ;
    for (i = 1 ; i < 256 ; i++)
    {
        if (books[i].book_id == book_id)
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
    for (i = 1 ; i < 256 ; i++)
    {
        if (members[i].id == id)
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
        if (members[i].id == -1) {break;}
        printf("\n");
        printf("-----------------第 %d 筆----------------" , i);
        printf("\n");
        printf("會員編號: %d ", members[i].id);
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
        printf("會員權限: %d ", members[i].power);
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
        if(strlen(books[i].BorrowDay)>0)
        {
            printf("借書日期: %s \n",  books[i].BorrowDay);
            printf("到期日期: %s \n",  books[i].DeadLineDay);
        }
        printf("書籍以被借出數量: %d ", books[i].state_book);
        printf("\n");
        printf("-----------------------------------------");
        printf("\n");
        counter = counter + 1;
    }
    printf("共%d筆資料\n", counter);
}
//顯示借閱紀錄
void showData(struct DATA data[], int id, int index)
{
    int i, j;
    int county = 0;
    printf("您已借下列書籍:\n");
    for (i = 1; i <= data[index].book_num; i++) {
        printf("\n");
        printf("----------------------------------------- \n");
        printf("第%d本 \n", i );
        printf("編號是: %d \n", data[index].book_id[i]);
        for (j = 1; j <= 256; j++) {
            if (books[j].book_id == data[index].book_id[i]) {
                printf("書籍名稱: %s \n" , books[j].book_name);
                if(strlen(books[j].BorrowDay)>0)
                {
                    printf("借書日期: %s \n", books[j].BorrowDay);
                    printf("到期日期: %s \n", books[j].DeadLineDay);
                    printf("剩餘借用時間: %d 天\n", CheckDeadLine(books[j].DeadLineDay));
                }
            }
        }
        printf("----------------------------------------- \n");
        printf("\n");
        county = county + 1 ;
    }
    printf("\n");
    printf("共有 %d 本 \n", county);
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
            books[i].BorrowDay;
            printf("\t");
            books[i].DeadLineDay;
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
int addMember(struct MEMBER members[], struct DATA data[])
{
    int i , j ;
    int index ;
    int index_check = 1;
    int id ;
    int check_char;
    for ( i = 1 ; i < 256 ; i ++)
    {
        if (members[i].id == -1)
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
            while (index_check)
            {
                scanf("%s", members[i].member_name);
                if ((check_char = Checked_arrary_input(members[i].member_name, 1) ) == 1 )
                {
                    index_check = 0;
                } else
                {
                    index_check = 1;
                    printf("輸入格式錯誤!! (不可含有非法字元) 例: !@#$%^&*()_+=- .. \n") ;
                    printf("\t 請重新輸入:");
                }
            }
            index_check = 1 ;
            printf("\t");
            printf("輸入地址:");
            while (index_check)
            {
                scanf("%s", members[i].address_name);
                if ((check_char = Checked_arrary_input(members[i].address_name, 2) ) == 1 )
                {
                    index_check = 0;
                } else
                {
                    index_check = 1;
                    printf("輸入格式錯誤!! (不可含有非法字元) 例: !@#$%^&*()_+=- .. \n") ;
                    printf("\t 請重新輸入:");
                }
            }
            index_check = 1 ;
            printf("\t");
            printf("輸入帳號:");
            while (index_check)
            {
                scanf("%s", members[i].accout_name);
                if ((check_char = Checked_arrary_input(members[i].accout_name, 3) ) == 1 )
                {
                    index_check = 0;
                } else
                {
                    index_check = 1;
                    printf("輸入格式錯誤!! (帳號至少要有三個英文八個數字和不能亂碼)\n") ;
                    printf("\t 請重新輸入:");
                }
            }
            index_check = 1 ;
            printf("\t");
            printf("輸入密碼:");
            while (index_check)
            {
                scanf("%s", members[i].password_name);
                if ((check_char = Checked_arrary_input(members[i].password_name, 4) ) == 1 )
                {
                    index_check = 0;
                } else
                {
                    index_check = 1;
                    printf("輸入格式錯誤!! (密碼至少要有三個英文八個數字和不能亂碼)\n") ;
                    printf("\t 請重新輸入:");
                }
            }
            index_check = 1 ;
            printf("\t");
            printf("輸入電話:");
            while (index_check)
            {
                scanf("%s", members[i].phone_name);
                if ((check_char = Checked_arrary_input(members[i].phone_name, 5) ) == 1 )
                {
                    index_check = 0;
                } else
                {
                    index_check = 1;
                    printf("輸入格式錯誤!! (電話至少要有10位數不能有英文不能亂碼)\n") ;
                    printf("\t 請重新輸入:");
                }
            }
            index_check = 1 ;
            printf("\t");
            printf("輸入電子信箱:");
            while (index_check)
            {
                scanf("%s", members[i].email_name);
                if ((check_char = Checked_arrary_input(members[i].email_name, 6) ) == 1 )
                {
                    index_check = 0;
                } else
                {
                    index_check = 1;
                    printf("輸入格式錯誤!! 請輸入正確的電子信箱格式)\n") ;
                    printf("\t 請重新輸入:");
                }
            }
            index_check = 1 ;
            printf("\t");
            printf("輸入性別 0:woman 1: man :");

            while (index_check)
            {
                fflush(stdin);
                scanf("%d", &members[i].man);
                if (members[i].man == 0 || members[i].man == 1)
                {
                    index_check = 0;
                }
                else
                {
                    index_check = 1;
                    printf("輸入錯誤請重新輸入");
                }
            }
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
    int i, j, k;
    int index1;
    index1 = searchBooks(books, book_id);
    if(data[index].book_num>0)
    {
        for (k = 1; k <= data[index].book_num; k++) {
            for (j = 1; j <= 256; j++) {
                if (books[j].book_id == data[index].book_id[k]) {
                    if (CheckDeadLine(books[j].DeadLineDay) < 0)
                    {
                        printf("書籍名稱: %s 已過期尚未歸還 \n" , books[j].book_name);
                        return 6;//有過期的書籍沒有還
                    }
                }
            }
        }
    }
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
        //將借用日期及到期日期寫入books
        GetTimer(books[index1].BorrowDay, books[index1].DeadLineDay);
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
                strcpy(books[index1].BorrowDay, "");
                strcpy(books[index1].DeadLineDay, "");
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
            fprintf(fp, "\t");
            fprintf(fp, "%d", members[i].power);
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
            if(strlen(books[i].BorrowDay)>0)
            {
            fprintf(fp, "%s", books[i].BorrowDay);
            fprintf(fp, "\t");
            fprintf(fp, "%s", books[i].DeadLineDay);
            fprintf(fp, "\t");
            }
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

void admin_active()
{
    FILE * fp;
    char user;
    char choice;
    int id;
    int book_id;
    int index;
    int result;
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
            return 0;

        }
    }
    return 0;
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
    char accout[20];
    char password[20];

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
        printf("\n 請選擇要做的動作 ( 1: 新會員註冊 2: 會員登入 ):");
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

        case '2':
        case 'B':
        case 'b':
            printf("\n");

            printf("請輸入會員帳號:");
            scanf("\r%s", accout);
            printf("請輸入會員密碼:");
            scanf("\r%s", password);

            index = searchUser(members , accout , password);
            if (index < 0) {
                printf("帳號密碼錯誤 請重新輸入 \n");
                continue;
            }
            printf("\n");
            printf("歡迎 %s 使用此系統 \n" , members[index].member_name);
            printf("\t");
            if (members[index].power < 1)
            {
                printf("你的權限為 '一般會員' ");
            } else if (members[index].power == 1)
            {
                printf("你的權限為 '管理員' ");
                admin_active();
                return 0;
            }

            printf("\n");

            while (1) {
                fp = fopen(BOOK_FILE, "w");
                saveBooks(fp, books);
                fclose(fp);
                printf("\n");
                printf("請輸入指令\n");
                printf("1.我要借書 2.我要還書 3.顯示借還書資料 4. 顯示書庫資料 5.結束>");
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
                    case 6:
                        break;
                    }
                    fp = fopen(DATA_FILE, "w");
                    saveData(fp, data);
                    fclose(fp);
                    break;

                case '2':
                    if (data[index].book_num == 0) {
                        printf("\n");
                        printf("目前尚未借任何書籍\n");
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

                case '3': //顯示借書
                    showData(data, id, index);
                    break;
                case '4': //顯示書庫
                    showBooks(books);
                    break;
                case '5':
                    exit(1);
                }
            }
            break;

        case '1':
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
int Checked_arrary_input(char InputText[], int CheckType)
{
    int Loop_i, Input_array_count = 0, CheckAnswer = 1, InputEng = 0, InputNum = 0, InputSpace = 0, InputEmail = 0, InputError = 0, InpChin = 0;
    char Checked_Char;
    Input_array_count = strlen(InputText);
    if (Input_array_count > 0)
    {
        for (Loop_i = 0; Loop_i < Input_array_count; Loop_i++)
        {
            Checked_Char = InputText[Loop_i];
            if (isalpha(Checked_Char))
            {
                InputEng++;
            }
            else if (isdigit(Checked_Char))
            {
                InputNum++;
            }
            else if (isspace(Checked_Char))
            {
                InputSpace++;
            }
            else if (Checked_Char == 64)
            {
                InputEmail++;
            }
            else if (ispunct(Checked_Char))
            {
                InputError++;
            }
            else
            {
                InpChin++;
            }
        }
        switch (CheckType)
        {
        case 1:
            //名子判斷
            if ( InputEmail > 0 || InputError > 0 )//名字不能輸入亂碼
            {
                return CheckAnswer = -1;
            }
            break;

        case 2:
            //地址判斷
            if (InputEmail > 0 || InputError > 0)//地址不能有亂碼
            {
                return CheckAnswer = -2;
            }
            break;

        case 3:
            //帳號判斷
            if (InputEng < CHECKENGLISH || InputNum < CHECKNUMBER || InputEmail > 0 || InputError > 0)//帳號至少要有三個英文八個數字和不能亂碼
            {
                return CheckAnswer = -3;
            }
            break;

        case 4:
            //密碼判斷
            if (InputEng < CHECKENGLISH || InputNum < CHECKNUMBER || InputEmail > 0 || InputError > 0 )//密碼至少要有三個英文八個數字和不能亂碼
            {
                return CheckAnswer = -4;
            }
            break;

        case 5:
            //電話判斷
            if (InputNum != PHOTONUM || InputEng > 0 || InputEmail > 0 || InputError > 0) //電話至少要有10位數不能有英文不能亂碼
            {
                return CheckAnswer = -5;
            }
            break;

        case 6:
            //電子信箱判斷
            if (InputEmail != 1)//不能有少於或多於一個@
            {
                return CheckAnswer = -6;
            }
            break;
        case 7:
            //性別判定
            if (!(InputText == "1" || InputText == "0")) //不是1就是0
            {
                return CheckAnswer = -7;
            }
            break;
        }
    }
    return CheckAnswer;
}

//判斷是不是有這個帳號密碼 不是回傳-1 是回傳大於1的值;
int searchUser(struct MEMBER members[], char name[], char Pwd[])
{
    int i, index;
    index = -1;
    for (i = 1; i < 256; i++)
    {
        if (strcmp(members[i].accout_name, name) == 0 && strcmp(members[i].password_name, Pwd) == 0 )
        {
            if (Checked_arrary_input(name, 3) && Checked_arrary_input(Pwd, 4))
            {
                index = i;
                return index;
            }
        }
    }
    return index;
}
//將表上的bookDeadLine丟入此函式
int CheckDeadLine(char DatatTime[])
{
    int i;
    int loop_i = 0;
    char CheckDataTime[10] = "";
    char Year[4], Month[2], Day[2];
    char *delim = "-";
    char * pch;
    char Timer[10], DeadLine[10];
    int NowYear = 0, NowMonth = 0, NowDay = 0, DeadYear = 0, DeadMonth = 0, DeadDay = 0;
    time_t now;
    struct tm* timenow;
    time(&now);  //time()會將從1900年開始計算的秒數存入 now 這個結構體.
    timenow = localtime(&now); //將 now結構體轉化為本地時間
    NowYear = (int)(timenow->tm_year + 1900);
    NowMonth = timenow->tm_mon + 1;
    NowDay = timenow->tm_mday;
    strcpy(CheckDataTime, DatatTime);
    pch = strtok(CheckDataTime, delim);
    while (pch != NULL)
    {
        loop_i++;
        switch (loop_i)
        {
        case 1:
            strcpy(Year, pch);
            DeadYear = atoi(Year);
            break;
        case 2:
            strcpy(Month, pch);
            DeadMonth = atoi(Month);
            break;
        case 3:
            strcpy(Day, pch);
            DeadDay = atoi(Day);
            break;
        }
        pch = strtok (NULL, delim);
    }
    if (DeadYear == NowYear)
    {
        if (DeadMonth == NowMonth)
        {
            return (DeadDay - NowMonth);
        }
        else
        {
            switch (DeadMonth)
            {
            case 2:
                return (DeadDay + 31 - NowDay);
                break;
            case 3:
                return (DeadDay + 28 - NowDay);
                break;
            case 4:
                return (DeadDay + 31 - NowDay);
                break;
            case 5:
                return (DeadDay + 30 - NowDay);
                break;
            case 6:
                return (DeadDay + 31 - NowDay);
                break;
            case 7:
                return (DeadDay + 30 - NowDay);
                break;
            case 8:
                return (DeadDay + 31 - NowDay);
                break;
            case 9:
                return (DeadDay + 31 - NowDay);
                break;
            case 10:
                return (DeadDay + 30 - NowDay);
                break;
            case 11:
                return (DeadDay + 31 - NowDay);
                break;
            case 12:
                return (DeadDay + 30 - NowDay);
                break;
            }
        }
    }
    else
    {
        if (DeadMonth < NowMonth)
        {
            return (DeadDay + 31 - NowDay);
        }
    }
}
//丟現在的值同時回傳過期日期與修改樹輸入的現在的日期
void GetTimer(char DataTime[], char DeadLine[])
{
    char Timer[10];
    int StrYear = 0, StrMoonth = 0, StrDay = 0;
    time_t now;
    struct tm* timenow;
    time(&now);  //time()會將從1900年開始計算的秒數存入 now 這個結構體.
    timenow = localtime(&now); //將 now結構體轉化為本地時間
    StrYear = timenow->tm_year + 1900;
    StrMoonth = timenow->tm_mon + 1;
    StrDay = timenow->tm_mday;
    int2str(StrYear, Timer);
    strcat(DataTime, Timer );
    strcat(DataTime, "-");
    int2str(StrMoonth, Timer);
    strcat(DataTime, Timer );
    strcat(DataTime, "-");
    int2str(StrDay, Timer);
    strcat(DataTime, Timer );
    if (StrMoonth != 12)
    {
        StrYear = timenow->tm_year + 1900;
        StrMoonth = timenow->tm_mon + 2;
        StrDay = timenow->tm_mday;
        switch (StrMoonth)
        {
        case 1:
            if (StrDay == 31)
            {
                StrMoonth += 1;
                StrDay = 3;
            }
            break;
        case 3:
            if (StrDay == 31)
            {
                StrMoonth += 1;
                StrDay = 1;
            }
            break;
        case 5:
            if (StrDay == 31)
            {
                StrMoonth += 1;
                StrDay = 1;
            }
            break;
        case 8:
            if (StrDay == 31)
            {
                StrMoonth += 1;
                StrDay = 1;
            }
            break;
        case 10:
            if (StrDay == 31)
            {
                StrMoonth += 1;
                StrDay = 1;
            }
            break;
        }
        int2str(StrYear, Timer);
        strcat(DeadLine, Timer );
        strcat(DeadLine, "-");
        int2str(StrMoonth, Timer);
        strcat(DeadLine, Timer );
        strcat(DeadLine, "-");
        int2str(StrDay, Timer);
        strcat(DeadLine, Timer );
    }
    else
    {
        StrYear = timenow->tm_year + 1901;
        StrMoonth = 1;
        StrDay = timenow->tm_mday;
        int2str(StrYear, Timer);
        strcat(DeadLine, Timer );
        strcat(DeadLine, "-");
        int2str(StrMoonth, Timer);
        strcat(DeadLine, Timer );
        strcat(DeadLine, "-");
        int2str(StrDay, Timer);
        strcat(DeadLine, Timer );
    }
}
void int2str(int i, char *s) {
    sprintf(s, "%d", i);
}
