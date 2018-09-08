#include<stdio.h>
#define MAXNUM 256
#define MEMBER_FILE "member.log"
#define BOOK_FILE "book.log"
#define DATA_FILE "data.log"

struct MEMBER {
    int id;
    char member_name[10];
    char address_name[50];
    int age;
    char phone_name[20];
} members[MAXNUM];

struct BOOK {
    int book_id;
    char book_name[80];
    char club_name[80];
    int level;
    char date_name[10];
    int state_book;
} books[MAXNUM];

struct DATA {
    int id;
    char member_name[10];
    int book_num;
    int book_id[6];
} data[MAXNUM];

// 初始化會員資料
void initMember(struct MEMBER members[])
{
    int i;
    for (i = 0; i < 256; i++) {
        members[i].id = -1;
    }
}

// 初始化書籍資料
void initBooks(struct BOOK books[])
{
    int i;
    for (i = 0; i < 256; i++) {
        books[i].book_id = -1;
    }
}

// 初始化借書歸還資料
void initData(struct DATA data[])
{
    int i;
    for (i = 0; i < 256; i++) {
        data[i].id = -1;
    }
}

// 載入會員資料
void loadMember(FILE * fp, struct MEMBER members[])
{
    int i;
    i = 1;
    while (fscanf(fp, "%d", &members[i].id) != EOF) {
        fscanf(fp, "%s", members[i].member_name);
        fscanf(fp, "%s", members[i].address_name);
        fscanf(fp, "%d", &members[i].age);
        fscanf(fp, "%s", members[i].phone_name);
        i = i + 1;
    }
}

// 載入書籍資料
void loadBooks(FILE * fp, struct BOOK books[])
{
    int i;
    i = 1;
    while (fscanf(fp, "%d", &books[i].book_id) != EOF) {
        fscanf(fp, "%s", books[i].book_name);
        fscanf(fp, "%s", books[i].club_name);
        fscanf(fp, "%d", &books[i].level);
        fscanf(fp, "%s", books[i].date_name);
        fscanf(fp, "%d", &books[i].state_book);
        i = i + 1;
    }
}

// 載入借書紀錄
void loadData(FILE * fp, struct DATA data[])
{
    int i, j;
    i = 1;
    while (fscanf(fp, "%d", &data[i].id) != EOF) {
        fscanf(fp, "%d", &data[i].id);
        fscanf(fp, "%s", data[i].member_name);
        fscanf(fp, "%d", &data[i].book_num);
        for (j = 1; j <= data[i].book_num; j++) {
            fscanf(fp, "%d", &data[i].book_id[j]);
        }
        i = i + 1;
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

// 根據書籍ID搜尋該書籍的資料位置
int searchBooks(struct BOOK books[], int book_id)
{
    int i, index;
    index = -1;
    for (i = 1; i < 256; i++) {
        if (books[i].book_id == book_id) {
            index = i;
            return index;
        }
    }
    return index;
}

// 搜尋會員的資料位置
int searchMember(struct MEMBER members[], int id)
{
    int i, index;
    index = -1;
    for (i = 1; i < 256; i++) {
        if (members[i].id == id) {
            index = i;
            return index;
        }
    }
    return index;
}

// 顯示會員資料
void showMember(struct MEMBER members[])
{
    int i, counter;
    counter = 0;
    printf("已加入的會員=> \n");
    for (i = 1; i <= 256; i++) {
        if (members[i].id == -1) {
            break;
        }
        printf("%d ", members[i].id);
        printf("\t");
        printf("%s ", members[i].member_name);
        printf("\t");
        printf("%s ", members[i].address_name);
        printf("\t");
        printf("%d ", members[i].age);
        printf("\t");
        printf("%s ", members[i].phone_name);
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
    printf("已擁有的書籍=> \n");
    for (i = 1; i <= 256; i++) {
        if (books[i].book_id == -1) {
            break;
        }
        printf("%d ", books[i].book_id);
        printf("\t");
        printf("%s ", books[i].book_name);
        printf("\t");
        printf("%s ", books[i].club_name);
        printf("\t");
        printf("%d ", books[i].level);
        printf("\t");
        printf("%s ", books[i].date_name);
        printf("\t");
        printf("%d ", books[i].state_book);
        printf("\n");
        counter = counter + 1;
    }
    printf("共%d筆資料\n", counter);
}

// 顯示借書歸還資料
void showData(struct DATA data[], int id, int index)
{
    int i;
    printf("您已借下列書籍:\n");
    for (i = 1; i <= data[index].book_num; i++) {
        printf("%d ", data[index].book_id[i]);
    }
    printf("\n");
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
            printf("輸入進書日期:");
            scanf("%s", books[i].date_name);
            printf("\t");
            books[i].state_book = 0;
            printf("\t");
            return 1;
        }
    }
}

// 刪除書籍
int subBooks(struct BOOK books[], int book_id)
{
    int i, j;
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
    int i, j;
    int index;
    int id;
    for (i = 1; i < 256; i++) {
        if (members[i].id == -1) {
            printf("\t");
            printf("輸入會員編號:");
            scanf("%d", &id);
            printf("\t");
            index = searchMember(members, id);
            if (index != -1) {
                return 2;
            }
            members[i].id = id;
            printf("輸入姓名:");
            scanf("%s", members[i].member_name);
            printf("\t");
            printf("輸入地址:");
            scanf("%s", members[i].address_name);
            printf("\t");
            printf("輸入年齡:");
            scanf("%d", &members[i].age);
            printf("\t");
            printf("輸入電話:");
            scanf("%s", members[i].phone_name);
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
        return 5;
    }
    if (data[index].book_num == 5) {
        return 4;
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
        return 1;
    }
    return 2;
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
                return 1;
            }
        }
        return 3;
    }
    return 2;
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
            fprintf(fp, "%d", members[i].age);
            fprintf(fp, "\t");
            fprintf(fp, "%s", members[i].phone_name);
            fprintf(fp, "\t");
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
