
void quickSortArray(SV LIST_MANG[], int u, int v, int tieuChi)
{
    SV mid = LIST_MANG[(u + v) / 2];
    int i = u;
    int j = v;
    do
    {
        if (tieuChi == 1)
        {
            while (cmpStr(LIST_MANG[i].maSV, mid.maSV) < 0)
                i++;
            while (cmpStr(LIST_MANG[j].maSV, mid.maSV) > 0)
                j--;
        }
        if (tieuChi == 2)
        {
            while (cmpStr(LIST_MANG[i].ten, mid.ten) < 0)
                i++;
            while (cmpStr(LIST_MANG[j].ten, mid.ten) > 0)
                j--;
        }
        if (tieuChi == 3)
        {
            while (LIST_MANG[i].diem < mid.diem)
                i++;
            while (LIST_MANG[j].diem > mid.diem)
                j--;
        }
        if (i <= j)
        {
            swap(LIST_MANG[i], LIST_MANG[j]);
            i++;
            j--;
        }
    } while (i <= j);
    if (u < j)
        quickSortArray(LIST_MANG, u, j, tieuChi);
    if (i < v)
        quickSortArray(LIST_MANG, i, v, tieuChi);
}

// #QuickSort dslk đơn
int partitionSinglyLinkedList(vector<pNODE_DON> &linkedListPointer, int start, int End, int tieuChi)
{
    SV pivot = linkedListPointer[End]->data;
    int current = start;
    int i;
    for (i = start; i < End; i++)
    {
        if (tieuChi == 1)
            if (cmpStr(linkedListPointer[i]->data.maSV, pivot.maSV) <= 0)
            {
                swap(linkedListPointer[i]->data, linkedListPointer[current]->data);
                current++;
            }
        if (tieuChi == 2)
            if (cmpStr(linkedListPointer[i]->data.ten, pivot.ten) <= 0)
            {
                swap(linkedListPointer[i]->data, linkedListPointer[current]->data);
                current++;
            }
        if (tieuChi == 3)
            if (linkedListPointer[i]->data.diem <= pivot.diem)
            {
                swap(linkedListPointer[i]->data, linkedListPointer[current]->data);
                current++;
            }
    }
    swap(linkedListPointer[End], linkedListPointer[current]);
    return current;
}
void quicksortSinglyLinkedList(vector<pNODE_DON> &linkedListPointer, int start, int End, int tieuChi)
{
    if (start < End)
    {
        int current = partitionSinglyLinkedList(linkedListPointer, start, End, tieuChi);
        {
            quicksortSinglyLinkedList(linkedListPointer, start, current - 1, tieuChi);
            quicksortSinglyLinkedList(linkedListPointer, current + 1, End, tieuChi);
        }
    }
    else
        return;
}

// #QuickSort dslk vòng
int partitionCircularLinkedList(vector<pNODE_VONG> &linkedListPointer, int start, int End, int tieuChi)
{
    SV pivot = linkedListPointer[End]->data;
    int current = start;
    int i;
    for (i = start; i < End; i++)
    {
        if (tieuChi == 1)
            if (cmpStr(linkedListPointer[i]->data.maSV, pivot.maSV) <= 0)
            {
                swap(linkedListPointer[i]->data, linkedListPointer[current]->data);
                current++;
            }
        if (tieuChi == 2)
            if (cmpStr(linkedListPointer[i]->data.ten, pivot.ten) <= 0)
            {
                swap(linkedListPointer[i]->data, linkedListPointer[current]->data);
                current++;
            }
        if (tieuChi == 3)
            if (linkedListPointer[i]->data.diem <= pivot.diem)
            {
                swap(linkedListPointer[i]->data, linkedListPointer[current]->data);
                current++;
            }
    }
    swap(linkedListPointer[End], linkedListPointer[current]);
    return current;
}
void quicksortCircularLinkedList(vector<pNODE_VONG> &linkedListPointer, int start, int End, int tieuChi)
{
    if (start < End)
    {
        int current = partitionCircularLinkedList(linkedListPointer, start, End, tieuChi);
        {
            quicksortCircularLinkedList(linkedListPointer, start, current - 1, tieuChi);
            quicksortCircularLinkedList(linkedListPointer, current + 1, End, tieuChi);
        }
    }
    else
        return;
}

// #QuickSort dslk kép
int partitionDoublyLinkedList(vector<pNODE_KEP> &linkedListPointer, int start, int End, int tieuChi)
{
    SV pivot = linkedListPointer[End]->data;
    int current = start;
    int i;
    for (i = start; i < End; i++)
    {
        if (tieuChi == 1)
            if (cmpStr(linkedListPointer[i]->data.maSV, pivot.maSV) <= 0)
            {
                swap(linkedListPointer[i]->data, linkedListPointer[current]->data);
                current++;
            }
        if (tieuChi == 2)
            if (cmpStr(linkedListPointer[i]->data.ten, pivot.ten) <= 0)
            {
                swap(linkedListPointer[i]->data, linkedListPointer[current]->data);
                current++;
            }
        if (tieuChi == 3)
            if (linkedListPointer[i]->data.diem <= pivot.diem)
            {
                swap(linkedListPointer[i]->data, linkedListPointer[current]->data);
                current++;
            }
    }
    swap(linkedListPointer[End], linkedListPointer[current]);
    return current;
}
void quicksortDoublyLinkedList(vector<pNODE_KEP> &linkedListPointer, int start, int End, int tieuChi)
{
    if (start < End)
    {
        int current = partitionDoublyLinkedList(linkedListPointer, start, End, tieuChi);
        {
            quicksortDoublyLinkedList(linkedListPointer, start, current - 1, tieuChi);
            quicksortDoublyLinkedList(linkedListPointer, current + 1, End, tieuChi);
        }
    }
    else
        return;
}

// #Ham tong hop QuickSort dslk
void quickSortLinkedList(LIST_VONG &dsVong, LIST_DON &dsDon, LIST_KEP &dsKep, int kieuDL, int tieuChi, int n)
{
    if (kieuDL == 2)
    {
        vector<pNODE_DON> linkedListPointer;
        for (pNODE_DON p = dsDon.pHead_Don; p != NULL; p = p->pNext_Don)
            linkedListPointer.push_back(p);

        quicksortSinglyLinkedList(linkedListPointer, 0, n - 1, tieuChi);

        khoitaoDSLKDon();
        for (int i = 0; i < n; i++)
            themVaoCuoiDSLKDon(dsDon, khoiTaoNodeDon(linkedListPointer[i]->data));

        linkedListPointer.clear();
        linkedListPointer.shrink_to_fit();
    }
    if (kieuDL == 3)
    {
        vector<pNODE_VONG> linkedListPointer;
        pNODE_VONG p = dsVong.pTail_Vong->pNext_Vong;
        while (p != dsVong.pTail_Vong)
        {
            linkedListPointer.push_back(p);
            p = p->pNext_Vong;
        }
        linkedListPointer.push_back(p);

        quicksortCircularLinkedList(linkedListPointer, 0, n - 1, tieuChi);
        khoiTaoDSLKVong(listVong);
        for (int i = 0; i < n; i++)
            themVaoCuoiDSLKVong(listVong, khoiTaoNodeVong(linkedListPointer[i]->data));

        linkedListPointer.clear();
        linkedListPointer.shrink_to_fit();
    }
    if (kieuDL == 4)
    {
        vector<pNODE_KEP> linkedListPointer;
        pNODE_KEP p = dsKep.pHead_Kep;
        while (p != NULL)
        {
            linkedListPointer.push_back(p);
            p = p->pNext_Kep;
        }

        quicksortDoublyLinkedList(linkedListPointer, 0, n - 1, tieuChi);

        khoiTaoDSLKKep(listKep);
        for (int i = 0; i < n; i++)
            themVaoCuoiDSLKKep(listKep, khoiTaoNodeKep(linkedListPointer[i]->data));

        linkedListPointer.clear();
        linkedListPointer.shrink_to_fit();
    }
}