#ifndef SUZUKI
#define SUZUKI

#include<iostream>
// #include<string>
using namespace std;

void tiga()
{
int pil;

cout << "Masukkan Pilihan : ";
cin  >> pil;

  cout<<endl;

switch(pil)
{
  case 1:
    cout << " Suzuki Ertiga " <<endl;
    cout << " Deskripsi : \n";
    cout << " Desain Eksterior : \n";
    cout << "- Suzuki Ertiga memiliki desain eksterior yang ramping dan modern dengan tampilan yang menggabungkan elemen-elemen SUV dan MPV. Garis-garisnya halus, dan model terbaru sering memiliki estetika yang menarik. " <<endl;
    cout << " Desain Interior : \n";
    cout << "- Ertiga memiliki interior yang luas dan dirancang untuk memberikan ruang yang maksimal bagi penumpang dan barang bawaan. Interior ini biasanya fleksibel dengan kursi belakang yang dapat dilipat untuk meningkatkan kapasitas bagasi." <<endl;
    cout <<"- Kursi pada Suzuki Ertiga berjumlah 7 ." <<endl;
    cout << " Kinerja Mesin : \n";
    cout <<"- Mobil ini biasanya dilengkapi dengan mesin bensin atau mesin diesel yang bertenaga, yang mampu memberikan kinerja yang baik, baik untuk perjalanan jarak jauh maupun penggunaan sehari-hari." <<endl;
    cout << "- Suzuki Ertiga memiliki kapasitas 1500 cc." <<endl;
    cout << " Fitur Keselamatan : \n";
    cout << " - Ertiga biasanya dilengkapi dengan fitur keselamatan seperti airbag ganda, rem cakram anti terkunci (ABS), sistem penggerak stabil (VSC), kontrol traksi, serta sistem pengereman elektronik (EBD) untuk meningkatkan keselamatan pengemudi dan penumpang. " <<endl;
      break;

  case 2:
    cout << " Suzuki Baleno " <<endl;
    cout << " Deskripsi : \n";
    cout << " Desain Eksterior : \n";
    cout << "-  Suzuki Baleno memiliki desain eksterior yang modern dengan garis-garis yang bersih dan tampilan yang sering kali aerodinamis. Mobil ini menonjolkan gaya yang elegan dan minimalis. " <<endl;
    cout << " Desain Interior : \n";
    cout << "-  Meskipun ukurannya kompak, Baleno memiliki interior yang cukup luas untuk menampung penumpang dengan nyaman. Interior ini biasanya didesain dengan material berkualitas tinggi dan tampilan yang bersih. " <<endl;
    cout << "- Kursi pada Suzuki Baleno berjumlah 5. " <<endl;
    cout << " Kinerja Mesin : \n";
    cout << "- Mobil ini biasanya dilengkapi dengan mesin bensin yang cukup bertenaga untuk mobilitas perkotaan. Mesin ini memberikan kinerja yang baik dalam lingkungan perkotaan dan penggunaan sehari-hari. " <<endl;
    cout << "- Suzuki Baleno memiliki kapasitas 1462 cc." <<endl;
    cout << " Fitur Keselamatan : \n";
    cout << "- Meskipun sebagai mobil kompak, Baleno biasanya dilengkapi dengan fitur keselamatan penting seperti airbag ganda, rem cakram anti terkunci (ABS), sistem kontrol traksi, dan sabuk pengaman. " <<endl;
      break;

  case 3:
    cout << " Suzuki Karimun " <<endl;
    cout << " Deskripsi : \n";
    cout << " Desain Eksterior : \n";
    cout << "-  Suzuki Karimun memiliki desain eksterior yang sederhana dan kompak. Garis-garisnya umumnya bersih dengan tampilan yang cocok untuk penggunaan perkotaan. " <<endl;
    cout << " Desain Interior : \n";
    cout << "-  Meskipun ukurannya compact, Karimun biasanya memiliki interior yang cukup luas untuk menampung beberapa penumpang. Interior sederhana dan fungsional dengan beberapa pilihan penyimpanan. " <<endl;
    cout << "- Kursi pada Suzuki Karimun berjumlah 5. " <<endl;
    cout << " Kinerja Mesin : \n";
    cout << "- Suzuki Karimun biasanya dilengkapi dengan mesin bensin yang cukup bertenaga untuk penggunaan perkotaan. Mesin ini biasanya memberikan kinerja yang memadai untuk kendaraan subkompak. " <<endl;
    cout << "- Suzuki Ertiga memiliki kapasitas 998 cc." <<endl;
    cout << " Fitur Keselamatan : \n";
    cout << "- Karimun biasanya memiliki fitur keselamatan dasar seperti airbag ganda untuk pengemudi dan penumpang depan, rem cakram, dan sabuk pengaman. " <<endl;
      break;

  case 4:
    cout << " Suzuki Ignis " <<endl;
    cout << " Deskripsi : \n";
    cout << " Desain Eksterior : \n";
    cout << "- Ignis memiliki desain eksterior yang unik dengan garis-garis yang mencolok dan tampilan yang sering kali menggabungkan elemen-elemen SUV dan hatchback. Mobil ini memiliki tampilan yang khas dan mencolok. " <<endl;
    cout << " Desain Interior : \n";
    cout << "- Meskipun ukurannya kompak, Ignis memiliki interior yang dirancang untuk memaksimalkan penggunaan ruang. Interior ini seringkali fleksibel dengan kursi yang dapat dilipat untuk meningkatkan kapasitas bagasi. " <<endl;
    cout << "- Kursi pada Suzuki Ignis berjumlah 5. " <<endl;
    cout << " Kinerja Mesin : \n";
    cout << "- Mobil ini biasanya dilengkapi dengan mesin bensin yang cukup bertenaga untuk penggunaan sehari-hari di dalam kota. Mesin ini biasanya memberikan kinerja yang baik dan efisiensi bahan bakar yang memadai. " <<endl;
    cout << "- Suzuki Ignis memiliki kapasitas 1197 cc." <<endl;
    cout << " Fitur Keselamatan : \n";
    cout << "-  Ignis biasanya dilengkapi dengan fitur keselamatan seperti airbag ganda, rem cakram anti terkunci (ABS), sistem penggerak stabil (VSC), kontrol traksi, dan sabuk pengaman. " <<endl;
      break;

   default:
    cout<<"Pilihan tidak tersedia";
    
  }
}

#endif

