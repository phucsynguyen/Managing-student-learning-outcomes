#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_HOCPHAN 10


struct NgaySinh
{
	int Ngay,Thang,Nam;
};
struct Diem{
	float DiemBoPhan,DiemGK,DiemThi,DiemTB;
};

struct HocPhan{
	char MaHocPhan[10], TenHocPhan[50], NamHoc[10], HocKy[10];
	int SoTinChi;
	struct Diem diem;
};

struct SinhVien
{
	int MaSV;
	char Hoten[30],Diachi[100],Sdt[11],Lop[30];
	int SoLuongHocPhan;
	struct NgaySinh Ngaysinh;
	struct HocPhan danhSachHocPhan[MAX_HOCPHAN];
};


void MenuQuanLyHocTapSinhVien()
{
	printf("*******************************************************************\n");
	printf("**           QUAN LY THONG TIN HOC TAP SINH VIEN                 **\n");
	printf("**    1. Hien thi ket qua hoc tap cua sinh vien                  **\n");            
	printf("**    2. Them thong tin hoc phan                                 **\n");
	printf("**    3. Cap nhat thong tin hoc phan                             **\n");
	printf("**    4. Them diem cua hoc phan                                  **\n");
	printf("**    5. Cap nhat diem hoc phan                                  **\n");
	printf("**    6. Xoa hoc phan ra khoi bang diem                          **\n");
	printf("**    7. Sap xep hoc phan theo diem trung binh                   **\n");
	printf("**    8. Tim kiem hoc phan co diem trung binh cao nhat           **\n");
	printf("**    9. Tim kiem hoc phan theo ten                              **\n");
	printf("**   10. In ket qua hoc tap                                      **\n");
	printf("**   11. In ket qua hoc tap theo hoc ky                          **\n");
	printf("**   12. Quay lai menu chinh                                     **\n");
	printf("*******************************************************************\n");
}
void MenuQuanLySinhVien()
{
	printf("********************************************************\n");
	printf("**           QUAN LY THONG TIN SINH VIEN              **\n");
	printf("**    1. Hien thi danh sach sinh vien                 **\n");            
	printf("**    2. Hien thi danh sach sinh vien theo lop        **\n");
	printf("**    3. Them thong tin sinh vien                     **\n");
	printf("**    4. Cap nhat thong tin sinh vien                 **\n");
	printf("**    5. Xoa sinh vien ra khoi danh sach              **\n");
	printf("**    6. Sap xep sinh vien theo ho va ten             **\n");
	printf("**    7. Tim kiem sinh vien theo ma sinh vien         **\n");
	printf("**    8. Tim kiem sinh vien theo ten                  **\n");
	printf("**    9. Quay lai menu chinh                          **\n");
	printf("********************************************************\n");
}

float QuyDoiDiem(float diemTBH10) {
    
    if (diemTBH10 < 0.0 || diemTBH10 > 10.0) {
       
        return -1.0; 
    }

    
    return (diemTBH10 / 10.0) * 4.0;
}
int TimKiemTheoTenHocPhan(struct SinhVien ArrSinhVien[], int SoLuongSinhVien, char tenHocPhan[])
{
    for (int i = 0; i < SoLuongSinhVien; i++)
    {
        for (int j = 0; j < ArrSinhVien[i].SoLuongHocPhan; j++)
        {
            if (strcmp(ArrSinhVien[i].danhSachHocPhan[j].TenHocPhan, tenHocPhan) == 0)
            {
                return i;
            }
        }
    }
    
    return -1;
}
int TimKiemHocPhanTheoMaHP(struct HocPhan danhSachHocPhan[], int soLuongHocPhan, char maHocPhan[]) {
    for (int i = 0; i < soLuongHocPhan; i++) {
        if (strcmp(danhSachHocPhan[i].MaHocPhan, maHocPhan) == 0) {
            return i; 
        }
    }
    return -1; 
}
int TimKiemTheoMaSV(struct SinhVien ArrSinhVien[], int SoLuongSinhVien, int maSV){
	for (int i = 0; i < SoLuongSinhVien; i++)
	{
		if (ArrSinhVien[i].MaSV == maSV)
		{
			return i;
		}
	}
	return -1;
}
void HienThiDanhSachSV(struct SinhVien ArrSinhVien[], int SoLuongSinhVien)
{
	printf("DANH SACH SINH VIEN:\n");	
	printf("-----------------------------------------------------"
	"----------------------------------------------------------------\n");
	printf("Ma sinh vien\t Ho ten \t Ngay sinh \t Dia chi \t So dien thoai \t\tLop\n");
	if(SoLuongSinhVien == 0){
		printf("Khong co sinh vien nao de hien thi!\n");
	}else{
		for (int i = 0; i < SoLuongSinhVien; i++)
		{
			
			printf("%d \t %s  \t %d/%d/%d\t %s \t %s\t \t%s\n", ArrSinhVien[i].MaSV, ArrSinhVien[i].Hoten, ArrSinhVien[i].Ngaysinh.Ngay, ArrSinhVien[i].Ngaysinh.Thang, ArrSinhVien[i].Ngaysinh.Nam, ArrSinhVien[i].Diachi, ArrSinhVien[i].Sdt, ArrSinhVien[i].Lop);
				
		}
		
	}
	printf("-----------------------------------------------------"
	"----------------------------------------------------------------\n");
}


void SapXepTheoHocKyNamHoc(struct HocPhan arr[], int n)
{
    int i, j;
    struct HocPhan temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
           
            if (strcmp(arr[i].NamHoc, arr[j].NamHoc) > 0 ||
                (strcmp(arr[i].NamHoc, arr[j].NamHoc) == 0 && strcmp(arr[i].HocKy, arr[j].HocKy) > 0))
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
void TimKiemVaInKetQuaTheoHocKyNamHoc(struct SinhVien ArrSinhVien[], int SoLuongSinhVien, int maSV, const char *hocKy, const char *namHoc, const char *tenFile)
{
    int index = TimKiemTheoMaSV(ArrSinhVien, SoLuongSinhVien, maSV);

    if (index == -1)
    {
        printf("Khong tim thay sinh vien co ma so %d.\n", maSV);
        return;
    }

    FILE *file = fopen(tenFile, "w");
    if (file == NULL)
    {
        printf("Khong the mo file de ghi.\n");
        return;
    }

    fprintf(file, "BANG DIEM SINH VIEN:\n");
	
    SapXepTheoHocKyNamHoc(ArrSinhVien[index].danhSachHocPhan, ArrSinhVien[index].SoLuongHocPhan);
    int soTinChiHocKy = 0;
    float diemTBHe10HocKy = 0.0;
    float diemTBHe4HocKy = 0.0;
    int soMonHocHocKy = 0;

    for (int i = 0; i < ArrSinhVien[index].SoLuongHocPhan; i++)
    {
        if (strcmp(ArrSinhVien[index].danhSachHocPhan[i].HocKy, hocKy) == 0 &&
            strcmp(ArrSinhVien[index].danhSachHocPhan[i].NamHoc, namHoc) == 0)
        {
            if (soMonHocHocKy == 0)
            {
            	fprintf(file, "-----------------------------------------------------"
                          "----------------------------------------------------------------\n");
                          printf( "-----------------------------------------------------"
                          "----------------------------------------------------------------\n");
                          printf("BANG DIEM SINH VIEN:\n");
                fprintf(file, "Hoc ky: %s - Nam hoc: %s\n", hocKy, namHoc);
                printf("Hoc ky: %s - Nam hoc: %s\n", hocKy, namHoc);
                fprintf(file, "Ma hoc phan\t Ten hoc phan \t So tin chi \tDiem Bo Phan \t Diem GK \tDiem Thi \t DiemTB\n");
                printf( "Ma hoc phan\t Ten hoc phan \t So tin chi \tDiem Bo Phan \t Diem GK \tDiem Thi \t DiemTB\n");
            }

            fprintf(file, "%s \t %s  \t \t %d\t\t%.1f \t\t %.1f \t\t%.1f \t\t %.1f\n", ArrSinhVien[index].danhSachHocPhan[i].MaHocPhan,
                    ArrSinhVien[index].danhSachHocPhan[i].TenHocPhan, ArrSinhVien[index].danhSachHocPhan[i].SoTinChi,
                    ArrSinhVien[index].danhSachHocPhan[i].diem.DiemBoPhan, ArrSinhVien[index].danhSachHocPhan[i].diem.DiemGK,
                    ArrSinhVien[index].danhSachHocPhan[i].diem.DiemThi, ArrSinhVien[index].danhSachHocPhan[i].diem.DiemTB);
                    printf( "%s \t %s  \t \t %d\t\t%.1f \t\t %.1f \t\t%.1f \t\t %.1f\n", ArrSinhVien[index].danhSachHocPhan[i].MaHocPhan,
                    ArrSinhVien[index].danhSachHocPhan[i].TenHocPhan, ArrSinhVien[index].danhSachHocPhan[i].SoTinChi,
                    ArrSinhVien[index].danhSachHocPhan[i].diem.DiemBoPhan, ArrSinhVien[index].danhSachHocPhan[i].diem.DiemGK,
                    ArrSinhVien[index].danhSachHocPhan[i].diem.DiemThi, ArrSinhVien[index].danhSachHocPhan[i].diem.DiemTB);

            if (ArrSinhVien[index].danhSachHocPhan[i].diem.DiemTB < 5.0)
            {
                continue;
            }

            soTinChiHocKy += ArrSinhVien[index].danhSachHocPhan[i].SoTinChi;
            diemTBHe10HocKy += ArrSinhVien[index].danhSachHocPhan[i].diem.DiemTB;
            diemTBHe4HocKy += QuyDoiDiem(diemTBHe10HocKy);
            soMonHocHocKy++;
        }
    }

    if (soMonHocHocKy == 0)
    {
    	printf( "Khong co hoc phan nao trong hoc ky %s - nam hoc %s.\n", hocKy, namHoc);
        fprintf(file, "Khong co hoc phan nao trong hoc ky %s - nam hoc %s.\n", hocKy, namHoc);
    }
    else
    {
        fprintf(file, "Tong so luong tin chi hien tai: %d\n", soTinChiHocKy);
        fprintf(file, "Diem trung binh he 10 hien tai: %.2f\n", soMonHocHocKy > 0 ? diemTBHe10HocKy / soMonHocHocKy : 0.0);
        fprintf(file, "Diem trung binh he 4 hien tai: %.2f\n", diemTBHe4HocKy);
        printf( "Tong so luong tin chi hien tai: %d\n", soTinChiHocKy);
        printf( "Diem trung binh he 10 hien tai: %.2f\n", soMonHocHocKy > 0 ? diemTBHe10HocKy / soMonHocHocKy : 0.0);
        printf( "Diem trung binh he 4 hien tai: %.2f\n", diemTBHe4HocKy);
        fprintf(file, "-----------------------------------------------------"
                          "----------------------------------------------------------------\n");
                          printf( "-----------------------------------------------------"
                          "----------------------------------------------------------------\n");
    }

    fclose(file);
    char choice;
    printf("Ban co muon in file ra khong? (Y/N): ");
    scanf(" %c", &choice);

    if (choice == 'Y' || choice == 'y') {
        printf("Da in file ket qua hoc phan thanh cong!\n");
    } else {
        remove(tenFile);  
    }
}

void HienThiKQHP(struct SinhVien ArrSinhVien[], int SoLuongSinhVien, int maSV)
{
    int index = TimKiemTheoMaSV(ArrSinhVien, SoLuongSinhVien, maSV);

    printf("BANG DIEM SINH VIEN:\n");
	
    SapXepTheoHocKyNamHoc(ArrSinhVien[index].danhSachHocPhan, ArrSinhVien[index].SoLuongHocPhan);
    int soTinChiHocKy = 0;
    float diemTBHe10HocKy = 0.0;
    float diemTBHe4HocKy = 0.0;
    int soMonHocHocKy = 0;

    for (int i = 0; i < ArrSinhVien[index].SoLuongHocPhan; i++)
    {
    	
        if (i == 0 || strcmp(ArrSinhVien[index].danhSachHocPhan[i].HocKy, ArrSinhVien[index].danhSachHocPhan[i - 1].HocKy) != 0 ||
            strcmp(ArrSinhVien[index].danhSachHocPhan[i].NamHoc, ArrSinhVien[index].danhSachHocPhan[i - 1].NamHoc) != 0)
        {
            if (i > 0)
            {
                
                printf("Tong so luong tin chi hien tai: %d\n", soTinChiHocKy);
                printf("Diem trung binh he 10 hien tai: %.2f\n", soMonHocHocKy > 0 ? diemTBHe10HocKy / soMonHocHocKy : 0.0);
                printf("Diem trung binh he 4 hien tai: %.2f\n", soMonHocHocKy > 0 ? diemTBHe4HocKy / soMonHocHocKy : 0.0);
            }

            
            soTinChiHocKy = 0;
            diemTBHe10HocKy = 0.0;
            diemTBHe4HocKy = 0.0;
            soMonHocHocKy = 0;

            printf("-----------------------------------------------------"
                   "----------------------------------------------------------------\n");
            printf("Hoc ky: %s - Nam hoc: %s\n", ArrSinhVien[index].danhSachHocPhan[i].HocKy, ArrSinhVien[index].danhSachHocPhan[i].NamHoc);
            printf("Ma hoc phan\t Ten hoc phan \t So tin chi \tDiem Bo Phan \t Diem GK \tDiem Thi \t DiemTB\n");
        }

        printf("%s \t %s  \t \t %d\t\t%.1f \t\t %.1f \t\t%.1f \t\t %.1f\n", ArrSinhVien[index].danhSachHocPhan[i].MaHocPhan,
               ArrSinhVien[index].danhSachHocPhan[i].TenHocPhan, ArrSinhVien[index].danhSachHocPhan[i].SoTinChi,
               ArrSinhVien[index].danhSachHocPhan[i].diem.DiemBoPhan, ArrSinhVien[index].danhSachHocPhan[i].diem.DiemGK,
               ArrSinhVien[index].danhSachHocPhan[i].diem.DiemThi, ArrSinhVien[index].danhSachHocPhan[i].diem.DiemTB);
               if (ArrSinhVien[index].danhSachHocPhan[i].diem.DiemTB < 5.0)
	    {
	        continue;
	    }

        soTinChiHocKy += ArrSinhVien[index].danhSachHocPhan[i].SoTinChi;
        diemTBHe10HocKy += ArrSinhVien[index].danhSachHocPhan[i].diem.DiemTB;
        diemTBHe4HocKy += QuyDoiDiem(diemTBHe10HocKy);  
        soMonHocHocKy++;
    }

    if (ArrSinhVien[index].SoLuongHocPhan == 0)
    {
        printf("Sinh vien chua co hoc phan nao.\n");
    }


    printf("Tong so luong tin chi hien tai: %d\n", soTinChiHocKy);
    printf("Diem trung binh he 10 hien tai: %.2f\n", soMonHocHocKy > 0 ? diemTBHe10HocKy / soMonHocHocKy : 0.0);
    printf("Diem trung binh he 4 hien tai: %.2f\n", diemTBHe4HocKy);

    printf("-----------------------------------------------------"
           "----------------------------------------------------------------\n");
}
void HienThiDanhSachSVTheoLop(struct SinhVien ArrSinhVien[], int SoLuongSinhVien, char lop[30])
{
	printf("DANH SACH SINH VIEN LOP %s:\n", lop);
	printf("-----------------------------------------------------"
	"----------------------------------------------------------------\n");
	printf("Ma sinh vien\t Ho ten \t Ngay sinh \t Dia chi \t So dien thoai \t\tLop\n");
		for (int i = 0; i < SoLuongSinhVien; i++)
		{
			if(strcmp(ArrSinhVien[i].Lop,lop) == 0){
				printf("%d \t %s  \t %d/%d/%d\t %s \t %s\t \t%s\n", ArrSinhVien[i].MaSV, ArrSinhVien[i].Hoten, ArrSinhVien[i].Ngaysinh.Ngay, ArrSinhVien[i].Ngaysinh.Thang, ArrSinhVien[i].Ngaysinh.Nam, ArrSinhVien[i].Diachi, ArrSinhVien[i].Sdt, ArrSinhVien[i].Lop);
			
			}			
		}	
	printf("-----------------------------------------------------"
	"----------------------------------------------------------------\n");	
}
void ThemSinhVien(struct SinhVien ArrSinhVien[], int SoLuongSinhVien)
{
	int maSV;
    printf("Nhap thong tin cho ban sinh vien thu %d\n", SoLuongSinhVien + 1);
    do {
        printf("Nhap vao ma sinh vien: ");
        scanf("%d", &maSV);
        int tonTai = 0; 
        for (int i = 0; i < SoLuongSinhVien; i++) {
            if (ArrSinhVien[i].MaSV == maSV) {
                tonTai = 1; 
                break;
            }
        }
        if (tonTai) {
            printf("Ma sinh vien da ton tai. Vui long nhap lai.\n");
        } else {
            ArrSinhVien[SoLuongSinhVien].MaSV = maSV;
        }
    } while (ArrSinhVien[SoLuongSinhVien].MaSV == 0);
	
	printf("Nhap vao ho va ten sinh vien: ");
	fflush(stdin);
	gets(ArrSinhVien[SoLuongSinhVien].Hoten);
	printf("Nhap vao ngay thang nam sinh vien: ");
	scanf("%d%*c%d%*c%d", &ArrSinhVien[SoLuongSinhVien].Ngaysinh.Ngay,&ArrSinhVien[SoLuongSinhVien].Ngaysinh.Thang,&ArrSinhVien[SoLuongSinhVien].Ngaysinh.Nam);
	printf("Nhap vao dia chi sinh vien: ");
	fflush(stdin);
	gets(ArrSinhVien[SoLuongSinhVien].Diachi);
	printf("Nhap vao so dien thoai cua sinh vien: ");
	fflush(stdin);
	gets(ArrSinhVien[SoLuongSinhVien].Sdt);
	printf("Nhap vao lop sinh vien: ");
	fflush(stdin);
	gets(ArrSinhVien[SoLuongSinhVien].Lop);
}

void ThemHocPhan(struct SinhVien ArrSinhVien[], int SoLuongSinhVien, int maSV)
{
    int index = TimKiemTheoMaSV(ArrSinhVien, SoLuongSinhVien, maSV);
    printf("Them hoc phan cho ban co ma so sinh vien la %d\n", maSV);
    int tonTai;

    do
    {
        tonTai = 0;

        if (ArrSinhVien[index].SoLuongHocPhan > 0)
        {
            printf("Nhap vao ma hoc phan: ");
            fflush(stdin);
            gets(ArrSinhVien[index].danhSachHocPhan[ArrSinhVien[index].SoLuongHocPhan].MaHocPhan);
			printf("Nhap vao ten hoc phan: ");
		    fflush(stdin);
		    gets(ArrSinhVien[index].danhSachHocPhan[ArrSinhVien[index].SoLuongHocPhan].TenHocPhan);
		    printf("Nhap vao nam hoc: ");
		    fflush(stdin);
		    gets(ArrSinhVien[index].danhSachHocPhan[ArrSinhVien[index].SoLuongHocPhan].NamHoc);
		    int hocKyHopLe = 0;
		    do
		    {
		        printf("Nhap vao hoc ky: ");
		        fflush(stdin);
		        gets(ArrSinhVien[index].danhSachHocPhan[ArrSinhVien[index].SoLuongHocPhan].HocKy);
		
		        if (strcmp(ArrSinhVien[index].danhSachHocPhan[ArrSinhVien[index].SoLuongHocPhan].HocKy, "1") == 0 ||
		            strcmp(ArrSinhVien[index].danhSachHocPhan[ArrSinhVien[index].SoLuongHocPhan].HocKy, "2") == 0)
		        {
		            hocKyHopLe = 1;
		        }
		        else
		        {
		            printf("Hoc ky khong hop le! Hay nhap lai\n");
		        }
		    } while (!hocKyHopLe);
		    
            
            for (int i = 0; i < ArrSinhVien[index].SoLuongHocPhan; i++)
            {
                if (strcmp(ArrSinhVien[index].danhSachHocPhan[i].MaHocPhan, ArrSinhVien[index].danhSachHocPhan[ArrSinhVien[index].SoLuongHocPhan].MaHocPhan) == 0 &&
                    strcmp(ArrSinhVien[index].danhSachHocPhan[i].HocKy, ArrSinhVien[index].danhSachHocPhan[ArrSinhVien[index].SoLuongHocPhan].HocKy) == 0 &&
                    strcmp(ArrSinhVien[index].danhSachHocPhan[i].NamHoc, ArrSinhVien[index].danhSachHocPhan[ArrSinhVien[index].SoLuongHocPhan].NamHoc) == 0)
                {
                    tonTai = 1;
                    printf("Hoc phan nay da co trong hoc ky va nam hoc nay. Vui long nhap lai.\n");
                    break;
                }
            }
        }
        else
        {
            printf("Nhap vao ma hoc phan: ");
            fflush(stdin);
            gets(ArrSinhVien[index].danhSachHocPhan[ArrSinhVien[index].SoLuongHocPhan].MaHocPhan);
        }
    } while (tonTai);


    printf("Nhap vao so tin chi: ");
    scanf("%d", &ArrSinhVien[index].danhSachHocPhan[ArrSinhVien[index].SoLuongHocPhan].SoTinChi);
    ArrSinhVien[index].SoLuongHocPhan++;
    printf("Them hoc phan thanh cong!\n");
}
void XoaSinhVien(struct SinhVien ArrSinhVien[], int* pSoLuongSinhVien, int maSV) {
    int indexSV = TimKiemTheoMaSV(ArrSinhVien, *pSoLuongSinhVien, maSV);
    if (indexSV != -1) {
        for (int i = indexSV; i < *pSoLuongSinhVien - 1; i++) {
            ArrSinhVien[i] = ArrSinhVien[i + 1];
        }
        (*pSoLuongSinhVien)--;
        printf("Xoa sinh vien thanh cong!\n");
    } else {
        printf("Khong tim thay sinh vien co maSV = %d\n", maSV);
    }
}

void XoaHocPhan(struct SinhVien ArrSinhVien[], int SoLuongSinhVien, int maSV) {
    int indexSV = TimKiemTheoMaSV(ArrSinhVien, SoLuongSinhVien, maSV);
        if (ArrSinhVien[indexSV].SoLuongHocPhan > 0) {
            printf("Danh sach hoc phan cua sinh vien %d:\n", maSV);
            for (int i = 0; i < ArrSinhVien[indexSV].SoLuongHocPhan; i++) {
                printf("%d. %s\n", i + 1, ArrSinhVien[indexSV].danhSachHocPhan[i].TenHocPhan);
            }

            int selected;
            printf("Nhap vao so thu tu hoc phan can xoa: ");
            scanf("%d", &selected);
            selected--;

            if (selected >= 0 && selected < ArrSinhVien[indexSV].SoLuongHocPhan) {
                
                for (int i = selected; i < ArrSinhVien[indexSV].SoLuongHocPhan - 1; i++) {
                    ArrSinhVien[indexSV].danhSachHocPhan[i] = ArrSinhVien[indexSV].danhSachHocPhan[i + 1];
                }

                ArrSinhVien[indexSV].SoLuongHocPhan--;

                printf("Xoa hoc phan thanh cong!\n");
            } else {
                printf("Lua chon khong hop le.\n");
            }
        } else {
            printf("Sinh vien chua co hoc phan nao de xoa.\n");
        }
   
}
void NhapDuLieu(char *thongTin, const char *moTa, int doDaiMax) {
    printf("%s", moTa);
    fflush(stdin);

    char temp[doDaiMax];
    if (fgets(temp, sizeof(temp), stdin) != NULL && temp[0] != '\n') {
        temp[strcspn(temp, "\n")] = 0;
        strncpy(thongTin, temp, doDaiMax - 1);
    }
}

void CapNhatHocPhan(struct SinhVien ArrSinhVien[], int SoLuongSinhVien, int maSV) {
    int index = TimKiemTheoMaSV(ArrSinhVien, SoLuongSinhVien, maSV);
    printf("Cap nhat hoc phan cho ban co ma so sinh vien la %d\n", maSV);
    if (ArrSinhVien[index].SoLuongHocPhan > 0) {
     
        printf("Danh sach hoc phan:\n");
        for (int i = 0; i < ArrSinhVien[index].SoLuongHocPhan; i++) {
            printf("%d. %s\n", i + 1, ArrSinhVien[index].danhSachHocPhan[i].TenHocPhan);
        }

        int selected;
        printf("Nhap vao so thu tu hoc phan can cap nhat: ");
        scanf("%d", &selected);
        selected--;

        if (selected >= 0 && selected < ArrSinhVien[index].SoLuongHocPhan) {
            
            NhapDuLieu(ArrSinhVien[index].danhSachHocPhan[selected].TenHocPhan, "Nhap vao ten hoc phan: ", sizeof(ArrSinhVien[index].danhSachHocPhan[selected].TenHocPhan));
            NhapDuLieu(ArrSinhVien[index].danhSachHocPhan[selected].NamHoc, "Nhap vao nam hoc: ", sizeof(ArrSinhVien[index].danhSachHocPhan[selected].NamHoc));
            NhapDuLieu(ArrSinhVien[index].danhSachHocPhan[selected].HocKy, "Nhap vao hoc ky: ", sizeof(ArrSinhVien[index].danhSachHocPhan[selected].HocKy));

           
            char tempSoTinChi[10];
            NhapDuLieu(tempSoTinChi, "Nhap vao so tin chi: ", sizeof(tempSoTinChi));
            if (tempSoTinChi[0] != '\0') {
                ArrSinhVien[index].danhSachHocPhan[selected].SoTinChi = atoi(tempSoTinChi);
            }

            printf("Cap nhat hoc phan thanh cong!\n");
        } else {
            printf("Lua chon khong hop le.\n");
        }
    } else {
        printf("Sinh vien chua co hoc phan nao de cap nhat.\n");
    }
}

void ThemDiemChoHocPhan(struct SinhVien ArrSinhVien[], int SoLuongSinhVien, int maSV, char maHocPhan[]) {
    
    int indexSV = TimKiemTheoMaSV(ArrSinhVien, SoLuongSinhVien, maSV);
    int indexHocPhan = TimKiemHocPhanTheoMaHP(ArrSinhVien[indexSV].danhSachHocPhan, ArrSinhVien[indexSV].SoLuongHocPhan, maHocPhan);
        if (indexHocPhan != -1) {
            printf("Nhap diem cho hoc phan %s:\n", ArrSinhVien[indexSV].danhSachHocPhan[indexHocPhan].TenHocPhan);

            printf("Diem Bo Phan: ");
            scanf("%f", &ArrSinhVien[indexSV].danhSachHocPhan[indexHocPhan].diem.DiemBoPhan);

            printf("Diem GK: ");
            scanf("%f", &ArrSinhVien[indexSV].danhSachHocPhan[indexHocPhan].diem.DiemGK);

            printf("Diem Thi: ");
            scanf("%f", &ArrSinhVien[indexSV].danhSachHocPhan[indexHocPhan].diem.DiemThi);

            
            ArrSinhVien[indexSV].danhSachHocPhan[indexHocPhan].diem.DiemTB = (ArrSinhVien[indexSV].danhSachHocPhan[indexHocPhan].diem.DiemBoPhan +
                                                                              ArrSinhVien[indexSV].danhSachHocPhan[indexHocPhan].diem.DiemGK +
                                                                              ArrSinhVien[indexSV].danhSachHocPhan[indexHocPhan].diem.DiemThi) / 3;

            printf("Them diem thanh cong!\n");
        } else {
            printf("Ma hoc phan khong co trong danh sach hoc phan cua sinh vien.\n");
        }
    }
void CapNhatDiemChoHocPhan(struct SinhVien ArrSinhVien[], int SoLuongSinhVien, int maSV) {
    int indexSV = TimKiemTheoMaSV(ArrSinhVien, SoLuongSinhVien, maSV);

    
        printf("Cap nhat diem cho ban co ma so sinh vien la %d\n", maSV);
        if (ArrSinhVien[indexSV].SoLuongHocPhan > 0) {

            printf("Danh sach hoc phan:\n");
            for (int i = 0; i < ArrSinhVien[indexSV].SoLuongHocPhan; i++) {
                printf("%d. %s\n", i + 1, ArrSinhVien[indexSV].danhSachHocPhan[i].TenHocPhan);
            }

            int selected;
            printf("Nhap vao so thu tu hoc phan can cap nhat diem: ");
            scanf("%d", &selected);
            selected--;

            if (selected >= 0 && selected < ArrSinhVien[indexSV].SoLuongHocPhan) {
                printf("Nhap diem cho hoc phan %s:\n", ArrSinhVien[indexSV].danhSachHocPhan[selected].TenHocPhan);

                printf("Diem Bo Phan: ");
                scanf("%f", &ArrSinhVien[indexSV].danhSachHocPhan[selected].diem.DiemBoPhan);

                printf("Diem GK: ");
                scanf("%f", &ArrSinhVien[indexSV].danhSachHocPhan[selected].diem.DiemGK);

                printf("Diem Thi: ");
                scanf("%f", &ArrSinhVien[indexSV].danhSachHocPhan[selected].diem.DiemThi);

               
                ArrSinhVien[indexSV].danhSachHocPhan[selected].diem.DiemTB =
                    (ArrSinhVien[indexSV].danhSachHocPhan[selected].diem.DiemBoPhan +
                     ArrSinhVien[indexSV].danhSachHocPhan[selected].diem.DiemGK +
                     ArrSinhVien[indexSV].danhSachHocPhan[selected].diem.DiemThi) / 3;

                printf("Cap nhat diem thanh cong!\n");
            } else {
                printf("Lua chon khong hop le.\n");
            }
        } else {
            printf("Sinh vien chua co hoc phan nao de cap nhat diem.\n");
        }
}   
void Swap(struct HocPhan *a, struct HocPhan *b) {
    struct HocPhan temp = *a;
    *a = *b;
    *b = temp;
}

void SapXepTheoDiemTB(struct HocPhan arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].diem.DiemTB < arr[j + 1].diem.DiemTB) {
                Swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}	
void HienThiKQHPTheoDTB(struct SinhVien ArrSinhVien[], int SoLuongSinhVien, int maSV) {
    int index = TimKiemTheoMaSV(ArrSinhVien, SoLuongSinhVien, maSV);
    printf("BANG DIEM SINH VIEN:\n");
    printf("-----------------------------------------------------"
           "----------------------------------------------------------------\n");
    printf("Ma hoc phan\t Ten hoc phan \t So tin chi \t Diem Bo Phan \t Diem GK \tDiem Thi \t DiemTB\n");

    if (ArrSinhVien[index].SoLuongHocPhan > 0) {
        
        SapXepTheoDiemTB(ArrSinhVien[index].danhSachHocPhan, ArrSinhVien[index].SoLuongHocPhan);

        for (int i = 0; i < ArrSinhVien[index].SoLuongHocPhan; i++) {
            printf("%s \t %s  \t \t %d\t\t%.1f \t\t %.1f \t\t%.1f \t\t %.1f\n",
                   ArrSinhVien[index].danhSachHocPhan[i].MaHocPhan,
                   ArrSinhVien[index].danhSachHocPhan[i].TenHocPhan,
                   ArrSinhVien[index].danhSachHocPhan[i].SoTinChi,
                   ArrSinhVien[index].danhSachHocPhan[i].diem.DiemBoPhan,
                   ArrSinhVien[index].danhSachHocPhan[i].diem.DiemGK,
                   ArrSinhVien[index].danhSachHocPhan[i].diem.DiemThi,
                   ArrSinhVien[index].danhSachHocPhan[i].diem.DiemTB);
        }
    } else {
        printf("Sinh vien chua co hoc phan nao.\n");
    }

    printf("-----------------------------------------------------"
           "----------------------------------------------------------------\n");
}
void HienThiHPDTBMaxt(struct SinhVien ArrSinhVien[], int SoLuongSinhVien, int maSV) {
    int index = TimKiemTheoMaSV(ArrSinhVien, SoLuongSinhVien, maSV);

    printf("MON HOC CO DIEM TRUNG BINH CAO NHAT:\n");
    printf("-----------------------------------------------------"
           "----------------------------------------------------------------\n");
    printf("Ma hoc phan\t Ten hoc phan \t So tin chi \t Diem Bo Phan \t Diem GK \tDiem Thi \t DiemTB\n");

    if (ArrSinhVien[index].SoLuongHocPhan > 0) {
        
        SapXepTheoDiemTB(ArrSinhVien[index].danhSachHocPhan, ArrSinhVien[index].SoLuongHocPhan);

        
        printf("%s \t %s  \t \t %d\t\t%.1f \t\t %.1f \t\t%.1f \t\t %.1f\n",
               ArrSinhVien[index].danhSachHocPhan[0].MaHocPhan,
               ArrSinhVien[index].danhSachHocPhan[0].TenHocPhan,
               ArrSinhVien[index].danhSachHocPhan[0].SoTinChi,
               ArrSinhVien[index].danhSachHocPhan[0].diem.DiemBoPhan,
               ArrSinhVien[index].danhSachHocPhan[0].diem.DiemGK,
               ArrSinhVien[index].danhSachHocPhan[0].diem.DiemThi,
               ArrSinhVien[index].danhSachHocPhan[0].diem.DiemTB);
    } else {
        printf("Sinh vien chua co hoc phan nao.\n");
    }
    printf("-----------------------------------------------------"
           "----------------------------------------------------------------\n");
}

void CapNhatThongTinSV(struct SinhVien ArrSinhVien[], int SoLuongSinhVien, int maSV)
{
    int index = TimKiemTheoMaSV(ArrSinhVien, SoLuongSinhVien, maSV);
    if (index != -1)
    {
        printf("Nhap lai thong tin cho ban sinh vien co ma so sinh vien la %d\n", maSV);

        char tempDiachi[100];
        if (fgets(tempDiachi, sizeof(tempDiachi), stdin) != NULL && tempDiachi[0] != '\n')
        {
            tempDiachi[strcspn(tempDiachi, "\n")] = 0;
            strncpy(ArrSinhVien[index].Diachi, tempDiachi, sizeof(ArrSinhVien[index].Diachi) - 1);
        }

 
        printf("Nhap vao ho va ten sinh vien muon sua doi (%s): ", ArrSinhVien[index].Hoten);
        char tempHoten[100];
        if (fgets(tempHoten, sizeof(tempHoten), stdin) != NULL && tempHoten[0] != '\n')
        {
            tempHoten[strcspn(tempHoten, "\n")] = 0;
            strncpy(ArrSinhVien[index].Hoten, tempHoten, sizeof(ArrSinhVien[index].Hoten) - 1);
        }
        
        

 
        printf("Nhap vao ngay thang nam sinh vien muon sua doi (%d/%d/%d): ",
               ArrSinhVien[index].Ngaysinh.Ngay, ArrSinhVien[index].Ngaysinh.Thang, ArrSinhVien[index].Ngaysinh.Nam);
        int newNgay, newThang, newNam;
        char tempNgay[10], tempThang[10], tempNam[10];
        if (fgets(tempNgay, sizeof(tempNgay), stdin) != NULL && tempNgay[0] != '\n' &&
            fgets(tempThang, sizeof(tempThang), stdin) != NULL && tempThang[0] != '\n' &&
            fgets(tempNam, sizeof(tempNam), stdin) != NULL && tempNam[0] != '\n')
        {
            sscanf(tempNgay, "%d", &newNgay);
            sscanf(tempThang, "%d", &newThang);
            sscanf(tempNam, "%d", &newNam);
            ArrSinhVien[index].Ngaysinh.Ngay = newNgay;
            ArrSinhVien[index].Ngaysinh.Thang = newThang;
            ArrSinhVien[index].Ngaysinh.Nam = newNam;
        }


        printf("Nhap vao dia chi sinh vien muon sua doi (%s): ", ArrSinhVien[index].Diachi);

        if (fgets(tempDiachi, sizeof(tempDiachi), stdin) != NULL && tempDiachi[0] != '\n')
        {
            tempDiachi[strcspn(tempDiachi, "\n")] = 0;
            strncpy(ArrSinhVien[index].Diachi, tempDiachi, sizeof(ArrSinhVien[index].Diachi) - 1);
        }


        printf("Nhap vao so dien thoai cua sinh vien muon sua doi (%s): ", ArrSinhVien[index].Sdt);
        char tempSdt[20];
        if (fgets(tempSdt, sizeof(tempSdt), stdin) != NULL && tempSdt[0] != '\n')
        {
            tempSdt[strcspn(tempSdt, "\n")] = 0;
            strncpy(ArrSinhVien[index].Sdt, tempSdt, sizeof(ArrSinhVien[index].Sdt) - 1);
        }


        printf("Nhap vao lop sinh vien muon sua doi (%s): ", ArrSinhVien[index].Lop);
        char tempLop[30];
        if (fgets(tempLop, sizeof(tempLop), stdin) != NULL && tempLop[0] != '\n')
        {
            tempLop[strcspn(tempLop, "\n")] = 0;
            strncpy(ArrSinhVien[index].Lop, tempLop, sizeof(ArrSinhVien[index].Lop) - 1);
        }

  
        printf("Cap nhat thong tin thanh cong!\n");
    }
    else
    {
        printf("Ma sinh vien khong co trong danh sach!\n");
    }
}

int TimKiemTheoHoTen(struct SinhVien ArrSinhVien[], int SoLuongSinhVien, char hoTen[30]){
	for (int i = 0; i < SoLuongSinhVien; i++)
	{
		if (strcmp(ArrSinhVien[i].Hoten,hoTen)== 0)
		{
			return i;
		}
	}
	return -1;
}

void SapXepSinhVienTheoTen(struct SinhVien danhSachSinhVien[], int soLuongSinhVien) {
    for (int i = 0; i < soLuongSinhVien - 1; i++) {
        for (int j = 0; j < soLuongSinhVien - i - 1; j++) {
            if (strcmp(danhSachSinhVien[j].Hoten, danhSachSinhVien[j + 1].Hoten) > 0) {
            
                struct SinhVien temp = danhSachSinhVien[j];
                danhSachSinhVien[j] = danhSachSinhVien[j + 1];
                danhSachSinhVien[j + 1] = temp;
            }
        }
    }
}
void InFileThongKeKetQua(struct SinhVien ArrSinhVien[], int SoLuongSinhVien, int maSV, const char *ThongKeKetQua)
{
    FILE *file = fopen(ThongKeKetQua, "w");
    if (file == NULL)
    {
        printf("Khong the mo file %s de ghi.\n", ThongKeKetQua);
        return;
    }

    int index = TimKiemTheoMaSV(ArrSinhVien, SoLuongSinhVien, maSV);
    fprintf(file, "BANG DIEM SINH VIEN:\n");
	fprintf(file, "Ho va ten: %s\n", ArrSinhVien[index].Hoten);
    fprintf(file, "Ngay sinh: %d/%d/%d\n", ArrSinhVien[index].Ngaysinh.Ngay, ArrSinhVien[index].Ngaysinh.Thang, ArrSinhVien[index].Ngaysinh.Nam);
    fprintf(file, "Lop: %s\n", ArrSinhVien[index].Lop);
    SapXepTheoHocKyNamHoc(ArrSinhVien[index].danhSachHocPhan, ArrSinhVien[index].SoLuongHocPhan);
    int soTinChiHocKy = 0;
    float diemTBHe10HocKy = 0.0;
    float diemTBHe4HocKy = 0.0;
    int soMonHocHocKy = 0;
    int tongSoTinChiTichLuy = 0;
    int tongSoMonHoc = 0;
    int soMonDatDuoc = 0;
    int soMonNo = 0;
    float tongDiemTBTichLuyHe10 = 0.0;


    for (int i = 0; i < ArrSinhVien[index].SoLuongHocPhan; i++)
    {
        if (i == 0 || strcmp(ArrSinhVien[index].danhSachHocPhan[i].HocKy, ArrSinhVien[index].danhSachHocPhan[i - 1].HocKy) != 0 ||
            strcmp(ArrSinhVien[index].danhSachHocPhan[i].NamHoc, ArrSinhVien[index].danhSachHocPhan[i - 1].NamHoc) != 0)
        {
            if (i > 0)
            {
                fprintf(file, "Tong so luong tin chi hien tai: %d\n", soTinChiHocKy);
                fprintf(file, "Diem trung binh he 10 hien tai: %.2f\n", soMonHocHocKy > 0 ? diemTBHe10HocKy / soMonHocHocKy : 0.0);
                fprintf(file, "Diem trung binh he 4 hien tai: %.2f\n", diemTBHe4HocKy);
            }

            soTinChiHocKy = 0;
            diemTBHe10HocKy = 0.0;
            diemTBHe4HocKy = 0.0;
            soMonHocHocKy = 0;

            fprintf(file, "-----------------------------------------------------"
                          "----------------------------------------------------------------\n");
            fprintf(file, "Hoc ky: %s - nam hoc: %s\n", ArrSinhVien[index].danhSachHocPhan[i].HocKy, ArrSinhVien[index].danhSachHocPhan[i].NamHoc);
            fprintf(file, "Ma hoc phan\t Ten hoc phan \t So tin chi \tDiem Bo Phan \t Diem GK \tDiem Thi \t DiemTB\n");
        }

        fprintf(file, "%s \t %s  \t \t %d\t\t%.1f \t\t %.1f \t\t%.1f \t\t %.1f\n", ArrSinhVien[index].danhSachHocPhan[i].MaHocPhan,
                ArrSinhVien[index].danhSachHocPhan[i].TenHocPhan, ArrSinhVien[index].danhSachHocPhan[i].SoTinChi,
                ArrSinhVien[index].danhSachHocPhan[i].diem.DiemBoPhan, ArrSinhVien[index].danhSachHocPhan[i].diem.DiemGK,
                ArrSinhVien[index].danhSachHocPhan[i].diem.DiemThi, ArrSinhVien[index].danhSachHocPhan[i].diem.DiemTB);
        
        if (ArrSinhVien[index].danhSachHocPhan[i].diem.DiemTB < 5.0)
        {
            continue;
        }

        soTinChiHocKy += ArrSinhVien[index].danhSachHocPhan[i].SoTinChi;
        diemTBHe10HocKy += ArrSinhVien[index].danhSachHocPhan[i].diem.DiemTB;
        diemTBHe4HocKy += QuyDoiDiem(diemTBHe10HocKy);
        soMonHocHocKy++;
    }

    if (ArrSinhVien[index].SoLuongHocPhan == 0)
    {
        fprintf(file, "Sinh vien chua co hoc phan nao.\n");
    }

    fprintf(file, "Tong so luong tin chi hien tai: %d\n", soTinChiHocKy);
    fprintf(file, "Diem trung binh he 10 hien tai: %.2f\n", soMonHocHocKy > 0 ? diemTBHe10HocKy / soMonHocHocKy : 0.0);
    fprintf(file, "Diem trung binh he 4 hien tai: %.2f\n", diemTBHe4HocKy);

    fprintf(file, "-----------------------------------------------------"
                   "----------------------------------------------------------------\n");
                   fprintf(file, "THONG KE KET QUA HOC TAP:\n");
for (int j = 0; j < ArrSinhVien[index].SoLuongHocPhan; j++)
        {
        	if (ArrSinhVien[index].danhSachHocPhan[j].diem.DiemTB < 5.0)
		    {
		        soMonNo++;
		        continue;
		    }
        	
            tongSoTinChiTichLuy += ArrSinhVien[index].danhSachHocPhan[j].SoTinChi;

            float diemTBH10 = ArrSinhVien[index].danhSachHocPhan[j].diem.DiemTB;
            if (diemTBH10 >= 5.0)
            {
                soMonDatDuoc++;
            }
            else
            {
                soMonNo++;
            }

            tongDiemTBTichLuyHe10 += diemTBH10;
            tongSoMonHoc++;
            
	}
	
    if (tongSoTinChiTichLuy > 0)
    {
        float diemTBTichLuyHe10 = tongDiemTBTichLuyHe10 / tongSoMonHoc;
        float diemTBTichLuyHe4 = QuyDoiDiem(diemTBTichLuyHe10);
        
        printf("Tong so luong tin chi tich luy: %d\n", tongSoTinChiTichLuy);
        printf("So mon dat duoc: %d\n", soMonDatDuoc);
        printf("So mon con no: %d\n", soMonNo);
        printf("Diem trung binh tich luy he 10: %.2f\n", diemTBTichLuyHe10);
        printf("Diem trung binh tich luy he 4: %.2f\n", diemTBTichLuyHe4);
    }
    else
    {
        printf("Khong co diem hop le de tinh toan.\n");
    }
    
    
    fprintf(file, "Tong so luong tin chi tich luy: %d\n", tongSoTinChiTichLuy);
    fprintf(file, "So mon dat duoc: %d\n", soMonDatDuoc);
    fprintf(file, "So mon con no: %d\n", soMonNo);
    fprintf(file, "Diem trung binh tich luy he 10: %.2f\n", tongDiemTBTichLuyHe10 / tongSoMonHoc);
    fprintf(file, "Diem trung binh tich luy he 4: %.2f\n", QuyDoiDiem(tongDiemTBTichLuyHe10 / tongSoMonHoc));

    fclose(file);
    char choice;
    printf("Ban co muon in file ra khong? (Y/N): ");
    scanf(" %c", &choice);

    if (choice == 'Y' || choice == 'y') {
        printf("Da in file ket qua hoc phan thanh cong!\n");
    } else {
        remove(ThongKeKetQua);  
    }
}


void Menu()
{
	printf("********************************************************\n");
	printf("**    HE THONG QUAN LY THONG TIN HOC TAP SINH VIEN    **\n");
	printf("**             1. Quan ly sinh vien                   **\n");
	printf("**           2. Quan ly hoc tap sinh vien             **\n");
	printf("**       3. Thong ke ket qua hoc tap sinh vien        **\n");
	printf("**             4. Thoat chuong trinh                  **\n");
	printf("********************************************************\n");
}
void DocFileSinhVien(char SV[], struct SinhVien ArrSinhVien[], int *SoLuongSinhVien) {
    FILE *file = fopen(SV, "r");
    if (file == NULL) {
        printf("Khong the mo file %s de doc.\n", SV);
        return;
    }

  
    fscanf(file, "%d", SoLuongSinhVien);

  
    for (int i = 0; i < *SoLuongSinhVien; i++) {
        fscanf(file, "%d %s %d/%d/%d %s %s %s %d", 
               &ArrSinhVien[i].MaSV,
               ArrSinhVien[i].Hoten,
               &ArrSinhVien[i].Ngaysinh.Ngay,
               &ArrSinhVien[i].Ngaysinh.Thang,
               &ArrSinhVien[i].Ngaysinh.Nam,
               ArrSinhVien[i].Diachi,
               ArrSinhVien[i].Sdt,
               ArrSinhVien[i].Lop,
               &ArrSinhVien[i].SoLuongHocPhan);

       
        for (int j = 0; j < ArrSinhVien[i].SoLuongHocPhan; j++) {
            fscanf(file, "%s %s %s %s %d %f %f %f %f",
                   ArrSinhVien[i].danhSachHocPhan[j].MaHocPhan,
                   ArrSinhVien[i].danhSachHocPhan[j].TenHocPhan,
                   ArrSinhVien[i].danhSachHocPhan[j].HocKy,
                   ArrSinhVien[i].danhSachHocPhan[j].NamHoc,
                   &ArrSinhVien[i].danhSachHocPhan[j].SoTinChi,
                   &ArrSinhVien[i].danhSachHocPhan[j].diem.DiemBoPhan,
                   &ArrSinhVien[i].danhSachHocPhan[j].diem.DiemGK,
                   &ArrSinhVien[i].danhSachHocPhan[j].diem.DiemThi,
                   &ArrSinhVien[i].danhSachHocPhan[j].diem.DiemTB);
        }
    }

    fclose(file);
}
void InFileKetQuaHocPhan(struct SinhVien ArrSinhVien[], int SoLuongSinhVien, int maSV, const char *KetQuaHocTap)
{
    FILE *file = fopen(KetQuaHocTap, "w");
    if (file == NULL)
    {
        printf("Khong the mo file %s de ghi.\n", KetQuaHocTap);
        return;
    }

    int index = TimKiemTheoMaSV(ArrSinhVien, SoLuongSinhVien, maSV);
    fprintf(file, "BANG DIEM SINH VIEN:\n");
	fprintf(file, "Ho va ten: %s\n", ArrSinhVien[index].Hoten);
    fprintf(file, "Ngay sinh: %d/%d/%d\n", ArrSinhVien[index].Ngaysinh.Ngay, ArrSinhVien[index].Ngaysinh.Thang, ArrSinhVien[index].Ngaysinh.Nam);
    fprintf(file, "Lop: %s\n", ArrSinhVien[index].Lop);
    SapXepTheoHocKyNamHoc(ArrSinhVien[index].danhSachHocPhan, ArrSinhVien[index].SoLuongHocPhan);
    int soTinChiHocKy = 0;
    float diemTBHe10HocKy = 0.0;
    float diemTBHe4HocKy = 0.0;
    int soMonHocHocKy = 0;

    for (int i = 0; i < ArrSinhVien[index].SoLuongHocPhan; i++)
    {
        if (i == 0 || strcmp(ArrSinhVien[index].danhSachHocPhan[i].HocKy, ArrSinhVien[index].danhSachHocPhan[i - 1].HocKy) != 0 ||
            strcmp(ArrSinhVien[index].danhSachHocPhan[i].NamHoc, ArrSinhVien[index].danhSachHocPhan[i - 1].NamHoc) != 0)
        {
            if (i > 0)
            {
                fprintf(file, "Tong so luong tin chi hien tai: %d\n", soTinChiHocKy);
                fprintf(file, "Diem trung binh he 10 hien tai: %.2f\n", soMonHocHocKy > 0 ? diemTBHe10HocKy / soMonHocHocKy : 0.0);
                fprintf(file, "Diem trung binh he 4 hien tai: %.2f\n", diemTBHe4HocKy);
            }

            soTinChiHocKy = 0;
            diemTBHe10HocKy = 0.0;
            diemTBHe4HocKy = 0.0;
            soMonHocHocKy = 0;

            fprintf(file, "-----------------------------------------------------"
                          "----------------------------------------------------------------\n");
            fprintf(file, "Hoc ky: %s - nam hoc: %s\n", ArrSinhVien[index].danhSachHocPhan[i].HocKy, ArrSinhVien[index].danhSachHocPhan[i].NamHoc);
            fprintf(file, "Ma hoc phan\t Ten hoc phan \t So tin chi \tDiem Bo Phan \t Diem GK \tDiem Thi \t DiemTB\n");
        }

        fprintf(file, "%s \t %s  \t \t %d\t\t%.1f \t\t %.1f \t\t%.1f \t\t %.1f\n", ArrSinhVien[index].danhSachHocPhan[i].MaHocPhan,
                ArrSinhVien[index].danhSachHocPhan[i].TenHocPhan, ArrSinhVien[index].danhSachHocPhan[i].SoTinChi,
                ArrSinhVien[index].danhSachHocPhan[i].diem.DiemBoPhan, ArrSinhVien[index].danhSachHocPhan[i].diem.DiemGK,
                ArrSinhVien[index].danhSachHocPhan[i].diem.DiemThi, ArrSinhVien[index].danhSachHocPhan[i].diem.DiemTB);
        
        if (ArrSinhVien[index].danhSachHocPhan[i].diem.DiemTB < 5.0)
        {
            continue;
        }

        soTinChiHocKy += ArrSinhVien[index].danhSachHocPhan[i].SoTinChi;
        diemTBHe10HocKy += ArrSinhVien[index].danhSachHocPhan[i].diem.DiemTB;
        diemTBHe4HocKy += QuyDoiDiem(diemTBHe10HocKy);
        soMonHocHocKy++;
    }

    if (ArrSinhVien[index].SoLuongHocPhan == 0)
    {
        fprintf(file, "Sinh vien chua co hoc phan nao.\n");
    }

    fprintf(file, "Tong so luong tin chi hien tai: %d\n", soTinChiHocKy);
    fprintf(file, "Diem trung binh he 10 hien tai: %.2f\n", soMonHocHocKy > 0 ? diemTBHe10HocKy / soMonHocHocKy : 0.0);
    fprintf(file, "Diem trung binh he 4 hien tai: %.2f\n", diemTBHe4HocKy);

    fprintf(file, "-----------------------------------------------------"
                   "----------------------------------------------------------------\n");

    fclose(file);
    char choice;
    printf("Ban co muon in file ra khong? (Y/N): ");
    scanf(" %c", &choice);

    if (choice == 'Y' || choice == 'y') {
        printf("Da in file ket qua hoc phan thanh cong!\n");
    } else {
        remove(KetQuaHocTap);  
    }
}

int main()
{
	char maHocPhan[10];
	char tenHocPhan[10];
	char hocKy[10];
	char namHoc[10];
	char tenFile[20];
	int maSV;
	int SoLuongSinhVien = 0, SoLuongHocPhan;
	int chon = 0;
	struct SinhVien ArrSinhVien[1000];
	struct HocPhan danhSachHocPhan[10];
	DocFileSinhVien("SV.txt", ArrSinhVien, &SoLuongSinhVien);
	do
	{
		Menu();
		printf("Nhap vao lua chon cua ban: ");
		scanf("%d", &chon);
		switch (chon)
		{
		case 1:
		{
			int chonQuanLySV = 0;
			do
			{
				MenuQuanLySinhVien();
				printf("Nhap vao lua chon cua ban: ");
				scanf("%d", &chonQuanLySV);
				switch (chonQuanLySV)
				{
				case 1:
				{
					HienThiDanhSachSV(ArrSinhVien,SoLuongSinhVien);
					break;
				}
				case 2:
				{
					HienThiDanhSachSV(ArrSinhVien,SoLuongSinhVien);
					if(SoLuongSinhVien == 0){
					}else{
					char lop[30];
					printf("Nhap vao lop can hien thi danh sach sinh vien: ");
					fflush(stdin);
					gets(lop);
					HienThiDanhSachSVTheoLop(ArrSinhVien, SoLuongSinhVien, lop);
					}
					break;
				}
				case 3:
				{
					ThemSinhVien(ArrSinhVien,SoLuongSinhVien);
					SoLuongSinhVien++;
					HienThiDanhSachSV(ArrSinhVien,SoLuongSinhVien);
					break;
				}
				case 4:
				{
					int maSV;
					printf("Nhap vao ma sinh vien can cap nhat: ");
					scanf("%d", &maSV);
					CapNhatThongTinSV(ArrSinhVien, SoLuongSinhVien, maSV);
					HienThiDanhSachSV(ArrSinhVien,SoLuongSinhVien);
					break;
				}
				case 5:
				{
					int maSV;
					printf("Nhap vao ma sinh vien muon xoa: ");
					scanf("%d", &maSV);
					XoaSinhVien(ArrSinhVien, &SoLuongSinhVien, maSV);
					HienThiDanhSachSV(ArrSinhVien,SoLuongSinhVien);
					break;
				}
				case 6:
				{
					SapXepSinhVienTheoTen(ArrSinhVien, SoLuongSinhVien);
					HienThiDanhSachSV(ArrSinhVien,SoLuongSinhVien);
					break;
				}
				case 7:
				{
					int maSV;
					printf("Nhap vao ma sinh vien muon tim kiem: ");
					scanf("%d", &maSV);
					int index = TimKiemTheoMaSV(ArrSinhVien,SoLuongSinhVien,maSV);
					if(index!=-1){
						printf("-----------------------------------------------------"
						"----------------------------------------------------------------\n");
						printf("Ma sinh vien\t Ho ten \t Ngay sinh \t Dia chi \t So dien thoai \t\tLop\n");
						printf("%d \t %s  \t %d\%d\%d\t %s \t %s\t \t%s\n", ArrSinhVien[index].MaSV, ArrSinhVien[index].Hoten, ArrSinhVien[index].Ngaysinh.Ngay, ArrSinhVien[index].Ngaysinh.Thang, ArrSinhVien[index].Ngaysinh.Nam, ArrSinhVien[index].Diachi, ArrSinhVien[index].Sdt, ArrSinhVien[index].Lop);
						printf("-----------------------------------------------------"
						"----------------------------------------------------------------\n");	
					}else{
						printf("Ma sinh vien khong co trong danh sach");
					}
					break;
				}
				case 8:
				{
					char hoTen[30];
					printf("Nhap vao ho ten sinh vien muon tim kiem: ");
					fflush(stdin);
					gets(hoTen);
					int index = TimKiemTheoHoTen(ArrSinhVien,SoLuongSinhVien,hoTen);
					if(index!=-1){	
						printf("-----------------------------------------------------"
						"----------------------------------------------------------------\n");
						printf("Ma sinh vien\t Ho ten \t Ngay sinh \t Dia chi \t So dien thoai \t\tLop\n");
						printf("%d \t %s  \t %d\%d\%d\t %s \t %s\t \t%s\n", ArrSinhVien[index].MaSV, ArrSinhVien[index].Hoten, ArrSinhVien[index].Ngaysinh.Ngay, ArrSinhVien[index].Ngaysinh.Thang, ArrSinhVien[index].Ngaysinh.Nam, ArrSinhVien[index].Diachi, ArrSinhVien[index].Sdt, ArrSinhVien[index].Lop);
						printf("-----------------------------------------------------"
						"----------------------------------------------------------------\n");	
					}else{
						printf("Ma sinh vien khong co trong danh sach\n");
					}
					break;
				}
				case 9:
				{
					printf("Ban da thoat khoi chuc nang quan ly sinh vien!\n");
					break;
				}
				default:
				{
					printf("Lua chon cua ban khong co trong menu, vui long nhap lai! \n");
					break;
				}
				}
			} while (chonQuanLySV != 9);
			break;
		}
		case 2:
		{
			HienThiDanhSachSV(ArrSinhVien,SoLuongSinhVien);
			if(SoLuongSinhVien == 0){
			printf("Khong co sinh vien trong danh sach vui long them thong tin sinh vien\n");
			ThemSinhVien(ArrSinhVien,SoLuongSinhVien);
			SoLuongSinhVien++;
			HienThiDanhSachSV(ArrSinhVien,SoLuongSinhVien);
			printf("Nhap vao ma sinh vien muon quan ly hoc tap: ");
			scanf("%d", &maSV);
			}else{
			printf("Nhap vao ma sinh vien muon quan ly hoc tap: ");
			scanf("%d", &maSV);
			}	
			int index = TimKiemTheoMaSV(ArrSinhVien,SoLuongSinhVien,maSV);
			if(index!=-1){
				printf("Ban da chon sinh vien co ma so %d de quan ly\n", maSV);
				int chonQuanLyHocTapSV = 0;
				do{	
				MenuQuanLyHocTapSinhVien();
				printf("Nhap vao lua chon cua ban: ");
				scanf("%d", &chonQuanLyHocTapSV);
				switch (chonQuanLyHocTapSV){
					case 1:{
						HienThiKQHP(ArrSinhVien,SoLuongSinhVien,maSV);
						break;
					}
					case 2:{
						ThemHocPhan(ArrSinhVien,SoLuongSinhVien,maSV);
						SoLuongHocPhan++;						
						break;
					}
					case 3:{
						CapNhatHocPhan(ArrSinhVien,SoLuongSinhVien,maSV);
						break;
					}
					case 4:{
						HienThiKQHP(ArrSinhVien,SoLuongSinhVien,maSV);
						char maHocPhan[10];
						printf("Nhap vao ma hoc phan muon them diem: ");
						fflush(stdin);
						gets(maHocPhan);	
						ThemDiemChoHocPhan(ArrSinhVien,SoLuongSinhVien,maSV,maHocPhan);
						HienThiKQHP(ArrSinhVien,SoLuongSinhVien,maSV);
						break;
					}
					case 5:{
						CapNhatDiemChoHocPhan(ArrSinhVien,SoLuongSinhVien,maSV);
						break;
					}
					case 6:{
						XoaHocPhan(ArrSinhVien, SoLuongSinhVien, maSV);
						HienThiKQHP(ArrSinhVien,SoLuongSinhVien,maSV);
					break;
						break;
					}
					case 7:{
						HienThiKQHPTheoDTB( ArrSinhVien, SoLuongSinhVien, maSV);
						break;
					}
					case 8:{
						HienThiHPDTBMaxt( ArrSinhVien, SoLuongSinhVien, maSV);
						break;
					}
					case 9:{
					char tenHocPhan[50];
					printf("Nhap vao ten hoc phan muon tim kiem: ");
					fflush(stdin);
					gets(tenHocPhan);
					
					int index = TimKiemTheoTenHocPhan(ArrSinhVien, SoLuongSinhVien, tenHocPhan);
					
					if (index != -1) {
					    printf("-----------------------------------------------------"
					           "----------------------------------------------------------------\n");
					    printf("Ma hoc phan\t Ten hoc phan \t So tin chi \t Diem Bo Phan \t Diem GK \tDiem Thi \t DiemTB\n");
					   
					        printf("%s \t %s  \t \t %d\t\t%.1f \t\t %.1f \t\t%.1f \t\t %.1f\n",
					               ArrSinhVien[index].danhSachHocPhan[index].MaHocPhan,
					               ArrSinhVien[index].danhSachHocPhan[index].TenHocPhan,
					               ArrSinhVien[index].danhSachHocPhan[index].SoTinChi,
					               ArrSinhVien[index].danhSachHocPhan[index].diem.DiemBoPhan,
					               ArrSinhVien[index].danhSachHocPhan[index].diem.DiemGK,
					               ArrSinhVien[index].danhSachHocPhan[index].diem.DiemThi,
					               ArrSinhVien[index].danhSachHocPhan[index].diem.DiemTB);
					    
					    printf("-----------------------------------------------------"
					           "----------------------------------------------------------------\n");
					} else {
					    printf("Ten hoc phan khong co trong danh sach\n");
					}
					break;
					}
					case 10:{
						HienThiKQHP(ArrSinhVien,SoLuongSinhVien,maSV);
						 InFileKetQuaHocPhan(ArrSinhVien, SoLuongSinhVien, maSV,"KetQuaHocTap.txt");
						break;
					}
					case 11:{
					HienThiKQHP(ArrSinhVien,SoLuongSinhVien,maSV);
					printf("Nhap vao hoc ky can in ra: ");
				    scanf("%s", &hocKy);
				
				    printf("Nhap vao nam hoc can in ra: ");
				    scanf("%s", &namHoc);
				
				    sprintf(tenFile, "%s_%s.txt", hocKy, namHoc);
				    TimKiemVaInKetQuaTheoHocKyNamHoc(ArrSinhVien, SoLuongSinhVien, maSV, hocKy, namHoc, tenFile);
						break;
					}
					case 12:{
						printf("Ban da thoat khoi chuc nang quan ly hoc tap sinh vien!\n");
						break;
					}
					default:{
						printf("Lua chon cua ban khong co trong menu, vui long nhap lai! \n");
						break;
					}
				}
			} while (chonQuanLyHocTapSV != 12);
					
				}else{
					printf("Ma sinh vien khong co trong danh sach!!\n");
				}
				break;
		}
		case 3:
		{
			HienThiDanhSachSV(ArrSinhVien,SoLuongSinhVien);
			if(SoLuongSinhVien == 0){
			printf("Khong co sinh vien trong danh sach vui long them thong tin sinh vien\n");
			
			}else{
			printf("Nhap vao ma sinh vien muon xem thong ke ket qua hoc tap: ");
			scanf("%d", &maSV);
				
			int index = TimKiemTheoMaSV(ArrSinhVien,SoLuongSinhVien,maSV);
			if(index!=-1){
				printf("Ban da chon sinh vien co ma so %d de xem thong ke ket qua hoc tap\n", maSV);
				HienThiKQHP(ArrSinhVien,SoLuongSinhVien,maSV);
				printf("THONG KE KET QUA HOC TAP:\n");
				InFileThongKeKetQua(ArrSinhVien, SoLuongSinhVien, maSV,"ThongKeKetQua.txt");

				printf("-----------------------------------------------------"
				"----------------------------------------------------------------\n");
			}else{
					printf("Ma sinh vien khong co trong danh sach!!\n");
				}
			}
			break;
		}
		case 4:
		{
			printf("Ban da thoat khoi chuong trinh!\n");
			break;
		}
		default:
		{
			printf("Lua chon cua ban khong co trong menu, vui long nhap lai! \n");
			break;
		}
		}
	} while (chon != 4);
}

