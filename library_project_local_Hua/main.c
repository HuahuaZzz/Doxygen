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

// ��l�Ʒ|�����
void initMember(struct MEMBER members[])
{
    int i;
    for (i = 0; i < 256; i++) {
        members[i].id = -1;
    }
}

// ��l�Ʈ��y���
void initBooks(struct BOOK books[])
{
    int i;
    for (i = 0; i < 256; i++) {
        books[i].book_id = -1;
    }
}

// ��l�ƭɮ��k�ٸ��
void initData(struct DATA data[])
{
    int i;
    for (i = 0; i < 256; i++) {
        data[i].id = -1;
    }
}

// ���J�|�����
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

// ���J���y���
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

// ���J�ɮѬ���
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

// �ھڮ��yID�j�M�Ӯ��y����Ʀ�m
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

// �j�M�|������Ʀ�m
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

// ��ܷ|�����
void showMember(struct MEMBER members[])
{
    int i, counter;
    counter = 0;
    printf("�w�[�J���|��=> \n");
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
    printf("�@%d�����\n", counter);
}

// ��ܮ��y���
void showBooks(struct BOOK books[])
{
    int i, counter;
    counter = 0;
    printf("�w�֦������y=> \n");
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
    printf("�@%d�����\n", counter);
}

// ��ܭɮ��k�ٸ��
void showData(struct DATA data[], int id, int index)
{
    int i;
    printf("�z�w�ɤU�C���y:\n");
    for (i = 1; i <= data[index].book_num; i++) {
        printf("%d ", data[index].book_id[i]);
    }
    printf("\n");
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
            printf("��J�i�Ѥ��:");
            scanf("%s", books[i].date_name);
            printf("\t");
            books[i].state_book = 0;
            printf("\t");
            return 1;
        }
    }
}

// �R�����y
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

// �s�W�|��
int addMember(struct MEMBER members[], struct DATA data[])
{
    int i, j;
    int index;
    int id;
    for (i = 1; i < 256; i++) {
        if (members[i].id == -1) {
            printf("\t");
            printf("��J�|���s��:");
            scanf("%d", &id);
            printf("\t");
            index = searchMember(members, id);
            if (index != -1) {
                return 2;
            }
            members[i].id = id;
            printf("��J�m�W:");
            scanf("%s", members[i].member_name);
            printf("\t");
            printf("��J�a�}:");
            scanf("%s", members[i].address_name);
            printf("\t");
            printf("��J�~��:");
            scanf("%d", &members[i].age);
            printf("\t");
            printf("��J�q��:");
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
                return 1;
            }
        }
        return 3;
    }
    return 2;
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
            fprintf(fp, "%d", members[i].age);
            fprintf(fp, "\t");
            fprintf(fp, "%s", members[i].phone_name);
            fprintf(fp, "\t");
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
        printf("\n�п�ܨ��� (A.�޲z�� B.�|�� C.�[�J�s�|�� D.����) >");
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

        case 'B':
        case 'b':
            printf("�п�J�|���s��:");
            scanf("\r%d", &id);
            index = searchData(data, id);
            if (index == -1) {
                printf("�L���|���άO��J���~\n");
                exit(1);
            }

            while (1) {
                fp = fopen(BOOK_FILE, "w");
                saveBooks(fp, books);
                fclose(fp);

                showBooks(books);
                showData(data, id, index);
                printf("�п�J���O\n");
                printf("1.�ɮ� 2.�ٮ� 3.��ܭ��ٮѸ�� 4.����>");
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
                    }

                    fp = fopen(DATA_FILE, "w");
                    saveData(fp, data);
                    fclose(fp);
                    break;

                case '2':
                    if (data[index].book_num == 0) {
                        printf("���ɥ�����y\n");
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
