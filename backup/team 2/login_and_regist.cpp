#include <iostream>
#include <cstdlib>
#include <string>
#include <regex>
#include <fstream>

using namespace std;

class userAuthentication {
public:
    
    string username, password, userId, passId,userTampil;
    string email;

private:
    bool loggedIn;
    void registration() {
    	short int count = 1;
        while(true){
          cout << "Masukkan email anda: ";
          cin >> email;
          if(isValidEmail(email)){
            break;
          } else {
            cout << "Email anda tidak valid, silahkan coba lagi!!!\n";
          }
        }
        
      
        cout << "Masukkan username anda: ";
        cin.ignore();
        getline(cin, username);

        cout << "Masukkan password anda: ";
        cin >> password;

        string confirmPassword;


        while(true){
            cout << "Masukkan ulang password anda: ";
            cin >> confirmPassword;

            if (confirmPassword == password) {
                cout << "\nRegistrasi berhasil\n";
                passId = password;
                userId = username;
                break;
            } else {
                cout << "Password tidak cocok!!!\n";
                if(count == 3){
                	cout << "Anda telah memasukkan password yang salah sebanyak "<< count << " kali.\n";
        			cout << "Silahkan coba lagi\n";
                	break;
				}
              // cin.get(); //system pause
              char c;
              cout << "Lanjut?";
              cin >> c;
              // system("cls");
            }
            
            count++;
        }
        
    }

    void login() {
        cout << "\nMasukkan username: ";
        cin.ignore();
        getline(cin, username);

        cout << "Masukkan password: ";
        cin >> password;
        
        if (username == userId && password == passId) {
            loggedIn = true;
            cout << "Login berhasil\n\n";
            userTampil = userId;
        } else {
            cout << "Login gagal! Periksa kembali username dan password Anda.\n";
            char lanjut;
            cout << "Apakah anda lupa password?(Y/N)\n";
            cin >> lanjut;
            if (lanjut == 'y' || lanjut == 'Y'){
                forgot();
            }
        }
    }

    void forgot() {
        string checkEmail;
        cout << "Masukkan email anda : ";
        cin >> checkEmail;

        // if (checkEmail == email){
        //     gantiPassword();
        // }

        if (isValidEmail(checkEmail)) {
          cout << "Email Valid\n";
          gantiPassword();
        } else {
          cout << "Email tidak valid" << '\n';
        }
    }

    void gantiPassword(){
        string newPass;
        string konfirmPass;
        cout << "Masukkan password lama anda : ";
        cin >> password;

        if(password == passId){
	        cout << "Masukkan password baru anda : ";
	        cin >> newPass;
	        
	        while(true){
	            cout <<"Masukkan ulang password baru anda : ";
	            cin >> konfirmPass;
	            if(newPass == konfirmPass){
	                cout << "Ubah password berhasil!\n";
	                passId = newPass;
	                break;
					        login();
	            }else{
	                cout << "Password tidak sesuai!\n";
	            }	
			}
        }
    }

    bool isValidEmail(string email) {
      const regex pattern("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");

      return std::regex_match(email, pattern);
    }

public:
   userAuthentication() {
        loggedIn = false; // Saat program dimulai, pengguna belum login.
    }
    void handleUser() {
        int choice;
        if (loggedIn) {
            cout << "Username saat ini: " << userTampil << "\n";
        } else {
            cout << "Username saat ini: (belum login)\n";
        }
        cout << endl;
        for (int i = 1; i <= 20; i++) {
            cout << "=";    
        }
        cout << '\n';

        cout << "1. Registrasi\n";
        cout << "2. Login\n";
        cout << "3. Ganti password\n";
        cout << "4. Keluar\n";
        
        for (int i = 1; i <= 20; i++) {
            cout << "=";
        }
        cout << '\n';
        

        cout << "Masukkan pilihan anda: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registration();
                break;
            case 2:
                login();
                break;
            case 3:
                gantiPassword();
                break;
            case 4:
                cout << "\nTerima kasih! Keluar dari program." << endl;
                exit(0);
            default:
                cout << "Pilihan tidak valid. Silakan pilih 1, 2, atau 3." << endl;
        }
    }
};




int main() {
    userAuthentication mhs;

    while (true) {
        mhs.handleUser();
    }

    return 0;
}