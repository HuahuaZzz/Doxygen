#include <stdio.h>
#include <string.h>
#include <time.h>
#define MAXNUM 256
#define MEMBER_FILE "member.log"
#define BOOK_FILE "book.log"
#define DATA_FILE "data.log"

//���b�P�_��
#include<ctype.h>
#define CHECKNUMBER 8
#define CHECKENGLISH 3
#define PHOTONUM 10



struct MEMBER { //member date struct
    int id; //����
    char member_name[10]; //�W�l
    char address_name[50]; //�a�}
    char accout_name[20]; //�b��
    char password_name[20]; //�K�X
    char phone_name[20]; //�q��
    char email_name[30]; //�q�l�H�c
    int man; // 1:man 0:woman
    int power; // �v�� 0 ���@�� 1���޲z��
} members[MAXNUM];

struct BOOK { //book date
    int book_id; //����
    char book_name[80]; //�W�l
    char club_name[80]; //���O
    int level; //����
    char date_name[10]; //���
    int state_book; //�O�_�w��
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


// ���J�|�����
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

// ���J���y���
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
        for (j = 1 ; j <= data[i].book_num; j++) //�P�w�ɤF�X���� �n����X��
        {
            fscanf(fp, "%d", &data[i].book_id[j]); // ��� ��ID
        }
        i = i + 1 ;
    }
}

// �ھڮ��yID�j�M�Ӯ��y����Ʀ�m
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

// �j�M�|������Ʀ�m
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

//��ܷ|�����
void showMember(struct MEMBER members[])
{
    int i , counter ;
    counter = 0 ; //�p�⦸��
    printf("�w�[�J���|�� => \n ");
    for (i = 1 ; i <= 256 ; i++)
    {
        if (members[i].id == -1) {break;}
        printf("\n");
        printf("-----------------�� %d ��----------------" , i);
        printf("\n");
        printf("�|���s��: %d ", members[i].id);
        printf("\n");
        printf("�|���W��: %s ", members[i].member_name);
        printf("\n");
        printf("�|���a�}: %s ", members[i].address_name);
        printf("\n");
        printf("�|���b��: %s ", members[i].accout_name);
        printf("\n");
        printf("�|���K�X: %s ", members[i].password_name);
        printf("\n");
        printf("�|���q��: %s ", members[i].phone_name);
        printf("\n");
        printf("�|���q�l�H�c: %s ", members[i].email_name);
        printf("\n");
        printf("�|���ʧO: %d (0: man 1: woman)", members[i].man);
        printf("\n");
        printf("�|���v��: %d ", members[i].power);
        printf("\n");
        printf("-----------------------------------------");
        printf("\n");
        counter = counter + 1;
    }
    printf("�@%d�����\n", counter);
}

// ��ܮ��y���
void showBooks(struct BOOK books[])
{
    int i, counter;
    counter = 0;
    printf("�Ѯw���: => \n");
    for (i = 1; i <= 256; i++) {
        if (books[i].book_id == -1) {
            break;
        }
        printf("\n");
        printf("-----------------�� %d ��----------------" , i);
        printf("\n");
        printf("���y�s��: %d ", books[i].book_id);
        printf("\n");
        printf("���y�W��: %s ", books[i].book_name);
        printf("\n");
        printf("�X�����W��: %s ", books[i].club_name);
        printf("\n");
        printf("���y����: %d ", books[i].level);
        printf("\n");
        printf("���y�i�Ѥ��: %s ", books[i].date_name);
        printf("\n");
        if(strlen(books[i].BorrowDay)>0)
        {
            printf("�ɮѤ��: %s \n",  books[i].BorrowDay);
            printf("������: %s \n",  books[i].DeadLineDay);
        }
        printf("���y�H�Q�ɥX�ƶq: %d ", books[i].state_book);
        printf("\n");
        printf("-----------------------------------------");
        printf("\n");
        counter = counter + 1;
    }
    printf("�@%d�����\n", counter);
}
//��ܭɾ\����
void showData(struct DATA data[], int id, int index)
{
    int i, j;
    int county = 0;
    printf("�z�w�ɤU�C���y:\n");
    for (i = 1; i <= data[index].book_num; i++) {
        printf("\n");
        printf("----------------------------------------- \n");
        printf("��%d�� \n", i );
        printf("�s���O: %d \n", data[index].book_id[i]);
        for (j = 1; j <= 256; j++) {
            if (books[j].book_id == data[index].book_id[i]) {
                printf("���y�W��: %s \n" , books[j].book_name);
                if(strlen(books[j].BorrowDay)>0)
                {
                    printf("�ɮѤ��: %s \n", books[j].BorrowDay);
                    printf("������: %s \n", books[j].DeadLineDay);
                    printf("�Ѿl�ɥήɶ�: %d ��\n", CheckDeadLine(books[j].DeadLineDay));
                }
            }
        }
        printf("----------------------------------------- \n");
        printf("\n");
        county = county + 1 ;
    }
    printf("\n");
    printf("�@�� %d �� \n", county);
}

// �s�W���y���
int addBooks(struct BOOK books[])
{
    int i;
    int index;
    int book_id;
    for (i = 1; i < 256; i++) {
        if (books[i].book_id == -1) {
            printf("\t");
            printf("��J���y�s��:");
            scanf("%d", &book_id);
            printf("\t");
            index = searchBooks(books, book_id);
            if (index != -1) {
                return 2;
            }
            books[i].book_id = book_id;
            printf("��J�ѦW:");
            scanf("%s", books[i].book_name);
            printf("\t");
            printf("��J�X�����W��:");
            scanf("%s", books[i].club_name);
            printf("\t");
            printf("��J�Ѫ�����:");
            scanf("%d", &books[i].level);
            printf("\t");
            printf("��J�i�Ѥ��: ");
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

// �ھڷ|��ID�j�M�ɾ\������m
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

// �R�����y
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


// �s�W�|��
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
            printf("��J�|���s��:");
            scanf("%d", &id);
            printf("\t");
            index = searchMember(members , id);
            if (index != -1)
            {
                return 2 ;
            }
            members[i].id = id ;
            printf("��J�m�W:");
            while (index_check)
            {
                scanf("%s", members[i].member_name);
                if ((check_char = Checked_arrary_input(members[i].member_name, 1) ) == 1 )
                {
                    index_check = 0;
                } else
                {
                    index_check = 1;
                    printf("��J�榡���~!! (���i�t���D�k�r��) ��: !@#$%^&*()_+=- .. \n") ;
                    printf("\t �Э��s��J:");
                }
            }
            index_check = 1 ;
            printf("\t");
            printf("��J�a�}:");
            while (index_check)
            {
                scanf("%s", members[i].address_name);
                if ((check_char = Checked_arrary_input(members[i].address_name, 2) ) == 1 )
                {
                    index_check = 0;
                } else
                {
                    index_check = 1;
                    printf("��J�榡���~!! (���i�t���D�k�r��) ��: !@#$%^&*()_+=- .. \n") ;
                    printf("\t �Э��s��J:");
                }
            }
            index_check = 1 ;
            printf("\t");
            printf("��J�b��:");
            while (index_check)
            {
                scanf("%s", members[i].accout_name);
                if ((check_char = Checked_arrary_input(members[i].accout_name, 3) ) == 1 )
                {
                    index_check = 0;
                } else
                {
                    index_check = 1;
                    printf("��J�榡���~!! (�b���ܤ֭n���T�ӭ^��K�ӼƦr�M����ýX)\n") ;
                    printf("\t �Э��s��J:");
                }
            }
            index_check = 1 ;
            printf("\t");
            printf("��J�K�X:");
            while (index_check)
            {
                scanf("%s", members[i].password_name);
                if ((check_char = Checked_arrary_input(members[i].password_name, 4) ) == 1 )
                {
                    index_check = 0;
                } else
                {
                    index_check = 1;
                    printf("��J�榡���~!! (�K�X�ܤ֭n���T�ӭ^��K�ӼƦr�M����ýX)\n") ;
                    printf("\t �Э��s��J:");
                }
            }
            index_check = 1 ;
            printf("\t");
            printf("��J�q��:");
            while (index_check)
            {
                scanf("%s", members[i].phone_name);
                if ((check_char = Checked_arrary_input(members[i].phone_name, 5) ) == 1 )
                {
                    index_check = 0;
                } else
                {
                    index_check = 1;
                    printf("��J�榡���~!! (�q�ܦܤ֭n��10��Ƥ��঳�^�夣��ýX)\n") ;
                    printf("\t �Э��s��J:");
                }
            }
            index_check = 1 ;
            printf("\t");
            printf("��J�q�l�H�c:");
            while (index_check)
            {
                scanf("%s", members[i].email_name);
                if ((check_char = Checked_arrary_input(members[i].email_name, 6) ) == 1 )
                {
                    index_check = 0;
                } else
                {
                    index_check = 1;
                    printf("��J�榡���~!! �п�J���T���q�l�H�c�榡)\n") ;
                    printf("\t �Э��s��J:");
                }
            }
            index_check = 1 ;
            printf("\t");
            printf("��J�ʧO 0:woman 1: man :");

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
                    printf("��J���~�Э��s��J");
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

// �R���|��
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


// �|���ɮ�
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
                        printf("���y�W��: %s �w�L���|���k�� \n" , books[j].book_name);
                        return 6;//���L�������y�S����
                    }
                }
            }
        }
    }
    if (books[index1].state_book == 1) {
        return 5; //���Ѥw�Q�ɨ�
    }
    if (data[index].book_num == 5) {
        return 4; //�z���ɮ��B�פw��
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
        //�N�ɥΤ���Ψ������g�Jbooks
        GetTimer(books[index1].BorrowDay, books[index1].DeadLineDay);
        return 1; //�ɮѧ���
    }
    return 2; //�ɮѧ���
}

// �|���ٮ�
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
                return 1;  //�ٮѧ���
            }
        }
        return 3; //���ɦ���
    }
    return 2; //�d�L����
}

// �x�s�|�����
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

// �x�s���y���
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

// �x�s���ٮѵ��G
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
        printf("�п�J���O\n");
        printf("\n1.�s�W���y 2.�R�����y 3.�W�[�|�� 4.�R���|��\n\
5.��ܮ��y 6.��ܷ|�� 7.����>");
        fflush(stdin);
        scanf("%c", &choice);
        switch (choice) {
        case '1':
            result = addBooks(books);
            if (result == 1) {
                printf("�s�W���y����\n");
            }
            if (result == 2) {
                printf("�w������\n");
            }
            fp = fopen(BOOK_FILE, "w");
            saveBooks(fp, books);
            fclose(fp);

            break;

        case '2':
            printf("��J���R�������y�s��:");
            scanf("%d", &book_id);
            result = subBooks(books, book_id);
            if (result == 1) {
                printf("�R�����y����\n");
            }
            if (result == 2) {
                printf("�d�L����\n");
            }
            if (result == 3) {
                printf("���ѥX�ɤ�,�L�k�R��\n");
            }
            break;

        case '3':
            result = addMember(members, data);
            if (result == 1) {
                printf("�s�W�|������\n");
            }
            if (result == 2)
                printf("�w�����|��\n");
            break;

        case '4':
            printf("�п�J���R�����|���s��:");
            scanf("%d", &id);
            result = subMember(members, data, id);
            if (result == 1)
                printf("�R���|������\n");
            if (result == 2)
                printf("�d�L���|��\n");
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

    // ���J�|�����
    fp = fopen(MEMBER_FILE, "r");
    loadMember(fp, members);
    fclose(fp);
    // ���J���y���
    fp = fopen(BOOK_FILE, "r");
    loadBooks(fp, books);
    fclose(fp);
    // ���J�ɮ��k�ٸ��
    fp = fopen(DATA_FILE, "r");
    loadData(fp, data);
    fclose(fp);
    printf("�z�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�{\n\
�x                                                �x\n\
�x�i���y���ɨt�Ρj                                �x\n\
�x���ϥΪ̯��ǥѦ��t�ζi����ٮ�,��ܤκ޲z���ʧ@ �x\n\
�|�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�}\n");

    while (1) {
        printf("\n �п�ܭn�����ʧ@ ( 1: �s�|�����U 2: �|���n�J ):");
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
                printf("�п�J���O\n");
                printf("\n1.�s�W���y 2.�R�����y 3.�W�[�|�� 4.�R���|��\n\
5.��ܮ��y 6.��ܷ|�� 7.����>");
                fflush(stdin);
                scanf("%c", &choice);
                switch (choice) {
                case '1':
                    result = addBooks(books);
                    if (result == 1) {
                        printf("�s�W���y����\n");
                    }
                    if (result == 2) {
                        printf("�w������\n");
                    }
                    fp = fopen(BOOK_FILE, "w");
                    saveBooks(fp, books);
                    fclose(fp);

                    break;

                case '2':
                    printf("��J���R�������y�s��:");
                    scanf("%d", &book_id);
                    result = subBooks(books, book_id);
                    if (result == 1) {
                        printf("�R�����y����\n");
                    }
                    if (result == 2) {
                        printf("�d�L����\n");
                    }
                    if (result == 3) {
                        printf("���ѥX�ɤ�,�L�k�R��\n");
                    }
                    break;

                case '3':
                    result = addMember(members, data);
                    if (result == 1) {
                        printf("�s�W�|������\n");
                    }
                    if (result == 2)
                        printf("�w�����|��\n");
                    break;

                case '4':
                    printf("�п�J���R�����|���s��:");
                    scanf("%d", &id);
                    result = subMember(members, data, id);
                    if (result == 1)
                        printf("�R���|������\n");
                    if (result == 2)
                        printf("�d�L���|��\n");
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

            printf("�п�J�|���b��:");
            scanf("\r%s", accout);
            printf("�п�J�|���K�X:");
            scanf("\r%s", password);

            index = searchUser(members , accout , password);
            if (index < 0) {
                printf("�b���K�X���~ �Э��s��J \n");
                continue;
            }
            printf("\n");
            printf("�w�� %s �ϥΦ��t�� \n" , members[index].member_name);
            printf("\t");
            if (members[index].power < 1)
            {
                printf("�A���v���� '�@��|��' ");
            } else if (members[index].power == 1)
            {
                printf("�A���v���� '�޲z��' ");
                admin_active();
                return 0;
            }

            printf("\n");

            while (1) {
                fp = fopen(BOOK_FILE, "w");
                saveBooks(fp, books);
                fclose(fp);
                printf("\n");
                printf("�п�J���O\n");
                printf("1.�ڭn�ɮ� 2.�ڭn�ٮ� 3.��ܭ��ٮѸ�� 4. ��ܮѮw��� 5.����>");
                fflush(stdin);
                scanf("\r%c", &choice);
                switch (choice) {
                case '1':
                    printf("�п�J���ɮѥ��N��, -1�����ɮ�> ");
                    scanf("%d", &book_id);
                    if (book_id == -1)  // �p�G�ɮѥN����-1
                    {
                        printf("�ɮѵ���\n");
                        printf("\n");
                        break;  // ���}�ɮѪ��j��
                    }
                    result = addData(data, books, book_id, index);
                    switch (result) {
                    case 1:
                        printf("�ɮѧ���\n");
                        break;
                    case 2:
                        printf("�ɮѧ���\n");
                        break;
                    case 3:
                        printf("�z�w�ɦ���\n");
                        break;
                    case 4:
                        printf("�z���ɮ��B�פw��\n");
                        break;
                    case 5:
                        printf("���Ѥw�Q�ɨ�\n");
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
                        printf("�ثe�|���ɥ�����y\n");
                        break;
                    }
                    printf("�п�J���ٮѥ��N��, -1�����ٮ�> ");
                    scanf("%d", &book_id);
                    if (book_id == -1)  // �p�G�ɮѥN����-1
                    {
                        printf("�ɮѵ���\n");
                        printf("\n");
                        break;  // ���}�ɮѪ��j��
                    }
                    result = subdata(data, books, book_id, index);
                    if (result == 1) {
                        printf("�ٮѧ���\n");
                    }
                    if (result == 2) {
                        printf("�d�L����\n");
                    }
                    if (result == 3) {
                        printf("���ɦ���\n");
                    }
                    fp = fopen(DATA_FILE, "w");
                    saveData(fp, data);
                    fclose(fp);
                    break;

                case '3': //��ܭɮ�
                    showData(data, id, index);
                    break;
                case '4': //��ܮѮw
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
                printf("�s�W�|������\n");
            }
            if (result == 2) {
                printf("�w�����|��\n");
            }
            break;

        case 'D':
        case 'd':
            exit(1);
        }

        // �x�s�|�����
        fp = fopen(MEMBER_FILE, "w");
        saveMember(fp, members);
        fclose(fp);
        // �x�s���y���
        fp = fopen(BOOK_FILE, "w");
        saveBooks(fp, books);
        fclose(fp);
        // �x�s���ٮѬ���
        fp = fopen(DATA_FILE, "w");
        saveData(fp, data);
        fclose(fp);
    }
}



//�r�꨾�b
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
            //�W�l�P�_
            if ( InputEmail > 0 || InputError > 0 )//�W�r�����J�ýX
            {
                return CheckAnswer = -1;
            }
            break;

        case 2:
            //�a�}�P�_
            if (InputEmail > 0 || InputError > 0)//�a�}���঳�ýX
            {
                return CheckAnswer = -2;
            }
            break;

        case 3:
            //�b���P�_
            if (InputEng < CHECKENGLISH || InputNum < CHECKNUMBER || InputEmail > 0 || InputError > 0)//�b���ܤ֭n���T�ӭ^��K�ӼƦr�M����ýX
            {
                return CheckAnswer = -3;
            }
            break;

        case 4:
            //�K�X�P�_
            if (InputEng < CHECKENGLISH || InputNum < CHECKNUMBER || InputEmail > 0 || InputError > 0 )//�K�X�ܤ֭n���T�ӭ^��K�ӼƦr�M����ýX
            {
                return CheckAnswer = -4;
            }
            break;

        case 5:
            //�q�ܧP�_
            if (InputNum != PHOTONUM || InputEng > 0 || InputEmail > 0 || InputError > 0) //�q�ܦܤ֭n��10��Ƥ��঳�^�夣��ýX
            {
                return CheckAnswer = -5;
            }
            break;

        case 6:
            //�q�l�H�c�P�_
            if (InputEmail != 1)//���঳�֩�Φh��@��@
            {
                return CheckAnswer = -6;
            }
            break;
        case 7:
            //�ʧO�P�w
            if (!(InputText == "1" || InputText == "0")) //���O1�N�O0
            {
                return CheckAnswer = -7;
            }
            break;
        }
    }
    return CheckAnswer;
}

//�P�_�O���O���o�ӱb���K�X ���O�^��-1 �O�^�Ǥj��1����;
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
//�N��W��bookDeadLine��J���禡
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
    time(&now);  //time()�|�N�q1900�~�}�l�p�⪺��Ʀs�J now �o�ӵ��c��.
    timenow = localtime(&now); //�N now���c����Ƭ����a�ɶ�
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
//��{�b���ȦP�ɦ^�ǹL������P�ק���J���{�b�����
void GetTimer(char DataTime[], char DeadLine[])
{
    char Timer[10];
    int StrYear = 0, StrMoonth = 0, StrDay = 0;
    time_t now;
    struct tm* timenow;
    time(&now);  //time()�|�N�q1900�~�}�l�p�⪺��Ʀs�J now �o�ӵ��c��.
    timenow = localtime(&now); //�N now���c����Ƭ����a�ɶ�
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
