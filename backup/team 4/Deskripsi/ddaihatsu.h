#ifndef DAIHATSU
#define DAIHATSU

#include<iostream>
// #include<string>
using namespace std;

void dua()
{
int pil;

cout << "Masukkan Pilihan : ";
cin  >> pil;

  cout<<endl;

switch(pil)
{
  case 1:
    cout << " Daihatsu Xenia " <<endl;
    cout << " Deskripsi : \n";
    cout << " Desain Eksterior : \n";
    cout << "- Daihatsu Xenia memiliki desain eksterior yang cukup konvensional, dengan tampilan yang sederhana dan fungsional. Ini adalah mobil yang berfokus pada kenyamanan dan fungsionalitas." <<endl;
    cout << " Desain Interior : \n";
    cout << "- Xenia biasanya memiliki interior yang luas dan dirancang untuk memberikan ruang yang maksimal bagi penumpang dan barang bawaan. Interior ini seringkali cukup fleksibel dengan kursi yang dapat dilipat untuk meningkatkan kapasitas bagasi." <<endl;
    cout <<"- Kursi pada Daihastu Xenia berjumlah 7 ." <<endl;
    cout << " Kinerja Mesin : \n";
    cout <<"-  Mobil ini biasanya dilengkapi dengan mesin bensin yang cukup bertenaga untuk penggunaan sehari-hari dan perjalanan jarak jauh. Mesin ini biasanya memberikan kinerja yang cukup baik untuk mobil MPV." <<endl;
    cout << "- Daihatsu Xenia memiliki kapasitas 1500 cc." <<endl;
    cout << " - Xenia biasanya dilengkapi dengan fitur keselamatan dasar seperti airbag ganda, rem cakram anti terkunci (ABS), sistem penggerak stabil (VSC), kontrol traksi, serta sistem pengereman elektronik (EBD) untuk meningkatkan keselamatan pengemudi dan penumpang. " <<endl;
      break;

  case 2:
    cout << " Daihatsu Ayla " <<endl;
    cout << " Deskripsi : \n";
    cout << " Desain Eksterior : \n";
    cout << "- Daihatsu Ayla memiliki desain eksterior yang kompak dan modern. Garis-garisnya sederhana, dengan fokus pada efisiensi aerodinamis dan manuverabilitas dalam kota." <<endl;
    cout << " Desain Interior : \n";
    cout << "- Meskipun ukurannya compact, Ayla memiliki interior yang dirancang untuk memaksimalkan penggunaan ruang. Ini mencakup kursi yang nyaman untuk penumpang depan dan belakang serta beberapa pilihan penyimpanan." <<endl;
    cout << "- Kursi pada Honda Mobilio berjumlah 5. " <<endl;
    cout << " Kinerja Mesin : \n";
    cout << "- Ayla biasanya dilengkapi dengan mesin yang cukup bertenaga untuk penggunaan sehari-hari di dalam kota. Mesin ini biasanya dikemas dengan teknologi yang mendukung efisiensi bahan bakar." <<endl;
    cout << "- Honda Mobilio memiliki kapasitas 1200 cc." <<endl;
    cout << " Fitur Keselamatan : \n";
    cout << "-  Mobil Ayla biasanya memiliki fitur keselamatan dasar seperti airbag ganda, rem cakram anti terkunci (ABS), dan sabuk pengaman." <<endl;
      break;

  case 3:
    cout << " Daihatsu Sigra " <<endl;
    cout << " Deskripsi : \n";
    cout << " Desain Eksterior : \n";
    cout << "-  Daihatsu Sigra memiliki desain eksterior yang modern dan kompak dengan garis-garis yang tegas dan tampilan yang sederhana. Mobil ini dirancang untuk menjadi kendaraan perkotaan yang mudah dikemudikan. " <<endl;
    cout << " Desain Interior : \n";
    cout << "-  Interior Sigra biasanya cukup luas untuk menampung penumpang dengan nyaman. Interior ini didesain dengan material berkualitas tinggi untuk memberikan tampilan yang baik." <<endl;
    cout << "- Kursi pada Daihatsu Sigra berjumlah 7. " <<endl;
    cout << " Kinerja Mesin : \n";
    cout << "- Mobil ini biasanya dilengkapi dengan mesin yang cukup bertenaga untuk penggunaan sehari-hari. Mesin ini bisa bensin atau varian mesin lain tergantung pada pasar dan model. " <<endl;
    cout << "- Daihastu Sigra memiliki kapasitas 1200 cc." <<endl;
    cout << " Fitur Keselamatan : \n";
    cout << "- Mobil ini biasanya dilengkapi dengan mesin bensin yang cukup bertenaga untuk penggunaan sehari-hari di perkotaan. Mesin ini memberikan kinerja yang baik dalam lingkungan perkotaan." <<endl;
      break;

   case 4:
    cout << " Daihatsu Rocky " <<endl;
    cout << " Deskripsi : \n";
    cout << " Desain Eksterior : \n";
    cout << "-  Daihatsu Rocky memiliki desain eksterior yang tangguh dan sporty dengan garis-garis yang tegas dan bentuk yang aerodinamis. Ini adalah mobil yang dirancang untuk tampil menarik dan berdaya tahan di berbagai kondisi. " <<endl;
    cout << " Desain Interior : \n";
    cout << "-  Interior Rocky biasanya dirancang dengan kenyamanan dan fungsionalitas sebagai prioritas. Material interior seringkali berkualitas tinggi, dan interior ini sering dilengkapi dengan fitur-fitur modern." <<endl;
    cout << "- Kursi pada Daihatsu Rocky berjumlah 5. " <<endl;
    cout << " Kinerja Mesin : \n";
    cout << "- Mobil ini biasanya dilengkapi dengan mesin yang bertenaga untuk mengatasi berbagai kondisi jalan dan medan. Performanya biasanya baik dalam perjalanan on-road maupun off-road. " <<endl;
    cout << "- Daihastu Rocky memiliki kapasitas 1198 cc." <<endl;
    cout << " Fitur Keselamatan : \n";
    cout << "- Kendaraan ini biasanya dilengkapi dengan berbagai fitur keselamatan seperti airbag ganda, rem cakram anti terkunci (ABS), sistem kontrol traksi, dan kontrol stabilitas kendaraan (VSC)." <<endl;
      break;

    default:
      cout<<"Pilihan tidak tersedia";
  }
}

#endif
    