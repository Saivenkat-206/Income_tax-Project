#include <iostream>
using namespace std;
class Salary{
public:
    //Monthly and Annual Salary is going to be calculated here
    double Monthly_Salary,Basic_Pay,Dearness_Allowance,House_Rent_Allowance,Travel_Allowance,Spl_Allowance,Performance_Allowance;
    void Enter_Monthly_Salary_Details(){
        cout<<"Enter Basic pay: ";
        cin>>Basic_Pay;
        cout<<"Enter Dearness allowance: ";
        cin>>Dearness_Allowance;
        cout<<"Enter House Rent Allowance: ";
        cin>>House_Rent_Allowance;
        cout<<"Enter Travel Allowance: ";
        cin>>Travel_Allowance;
        cout<<"Enter Special Allowance: ";
        cin>>Spl_Allowance;
        cout<<"Enter Performance Allowance: ";
        cin>>Performance_Allowance;
        Monthly_Salary = Basic_Pay+Dearness_Allowance+House_Rent_Allowance+Travel_Allowance+Spl_Allowance+Performance_Allowance;
    }
    double Annual_Salary,Bonus,Ex_Gratia,Annual_PI;
    void Enter_Annual_Salary_Details(){
        cout<<"Enter Bonus: ";
        cin>>Bonus;
        cout<<"Enter Ex-Gratia: ";
        cin>>Ex_Gratia;
        cout<<"Enter Annual Performance Incentive: ";
        cin>>Annual_PI;
        Annual_Salary = (Monthly_Salary*12)+Bonus+Ex_Gratia+Annual_PI;
        cout<<"Annual Salary: "<<Annual_Salary<<endl;
    }
};

class Deduction:public Salary{
public:
    double EPF,Std_Deductions,Proff_tax,PF,HRA_Deductions,ChapterVIA,gen_det;
    void set_gen_det(){
        Std_Deductions=50000.00;
        Proff_tax=2520.00;
        EPF=((Basic_Pay+Dearness_Allowance)*0.12)*12;
        gen_det=Annual_Salary-(EPF+Std_Deductions+Proff_tax);
    }
    void HRA_Calculations(){
        cout<<"Does the employee pay rent? (Type 1 for Yes or 0 for No): ";
        int choice;
        double rent;
        cin>>choice;
        if (choice==1){
            cout<<"Enter the rent paid to the landlord: ";
            cin>>rent;
            if (rent<House_Rent_Allowance && rent<(Basic_Pay+Dearness_Allowance)*0.5){
                HRA_Deductions=rent;
            }
            else if(House_Rent_Allowance<rent && House_Rent_Allowance<(Basic_Pay+Dearness_Allowance)*0.5){
                HRA_Deductions=House_Rent_Allowance;
            }
            else{
                HRA_Deductions=(Basic_Pay+Dearness_Allowance)*0.5;
            }
        }
        else{
            cout<<"Employee is not eligible for HRA deductions"<<endl;
        }
    }
    double LIC_Self_Family,Tution_Fee1,Tution_Fee2,Principle_House_Loan,National_Saving_Certificate,Postal_Saving_Scheme,Medical_Self_Family,Medical_Senior,National_Pension_Scheme,Interest_Save,Total_Deductions,Final_Taxable_Salary;
    void chapter6A(){
        cout<<"Enter LIC premium paid for self and family: ";
        cin>>LIC_Self_Family;
        cout<<"Tution fee allowed only for 2 children"<<endl;
        cout<<"Enter Tution fee for 1st child: ";
        cin>>Tution_Fee1;
        cout<<"Enter Tution fee for 2nd child: ";
        cin>>Tution_Fee2;
        cout<<"Enter principal amount for your hosing loan: ";
        cin>>Principle_House_Loan;
        cout<<"Enter National Saving Certificate Amount: ";
        cin>>National_Saving_Certificate;
        cout<<"Enter Postal Saving Scheme amount: ";
        cin>>Postal_Saving_Scheme;
        cout<<"Enter medical insurance amount paid for self and family(exclude senior citizens)(Max 25k): ";
        cin>>Medical_Self_Family;
        if (Medical_Self_Family>25000){
            Medical_Self_Family=25000;
        }
        cout<<"Enter medical insurance amount paid for Senior Citizens(Max 50k): ";
        cin>>Medical_Senior;
        if (Medical_Senior>50000){
            Medical_Senior=50000;
        }
        cout<<"Enter National pension scheme amount(Max 50k): ";
        cin>>National_Pension_Scheme;
        if (National_Pension_Scheme>50000){
            National_Pension_Scheme=50000;
        }
        cout<<"Enter the Interest received from savings account(Max 10k): ";
        cin>>Interest_Save;
        if (Interest_Save>10000){
            Interest_Save=10000;
        }
        ChapterVIA=LIC_Self_Family+Tution_Fee1+Tution_Fee2+Principle_House_Loan+National_Saving_Certificate+Postal_Saving_Scheme+Medical_Self_Family+Medical_Senior+National_Pension_Scheme+Interest_Save;
        Total_Deductions=gen_det+HRA_Deductions+ChapterVIA;
        Final_Taxable_Salary=Annual_Salary-Total_Deductions;
        cout<<"Total Deductions done: "<<Total_Deductions<<endl;
        cout<<"Final Taxable Salary: "<<Final_Taxable_Salary<<endl;
    }

};

class Tax_Applications: public Deduction{
public:
    double Total_Tax,Final_Income;
    int Age;
    void Generate_Tax(){
        cout<<"Tax to be calculated according to the old regime"<<endl;
        cout<<"Enter your age: ";
        cin>>Age;
        if (Final_Taxable_Salary<=250000){
            cout<<"Not eligible for taxation"<<endl;
        }
        else if(Final_Taxable_Salary>250000 && Final_Taxable_Salary<=300000){
            if (Age<60){
                cout<<"5% of income eligible for taxation"<<endl;
                Total_Tax=Final_Taxable_Salary*0.05;
            }
            else if(Age>=60){
                cout<<"Not eligible for taxation"<<endl;
            }
        }
        else if(Final_Taxable_Salary>300000 && Final_Taxable_Salary<=500000){
            if(Age<80){
                cout<<"5% of income eligible for taxation"<<endl;
                Total_Tax=Final_Taxable_Salary*0.05;
            }
            else if(Age>=80){
                cout<<"Not eligible for taxation"<<endl;
            }
        }
        else if(Final_Taxable_Salary>500000 && Final_Taxable_Salary<=1000000){
            cout<<"20% of income eligible for taxation"<<endl;
            Total_Tax=Final_Taxable_Salary*0.20;
        }
        else if(Final_Taxable_Salary>1000000){
            cout<<"30% of income eligible for taxation"<<endl;
            Total_Tax=Final_Taxable_Salary*0.30;
        }
        Final_Income=Final_Taxable_Salary-Total_Tax;
        cout<<"Final Income of the employee after taxation: "<<Final_Income<<endl;
    }
};

int main(){
    Tax_Applications T;
    T.Enter_Monthly_Salary_Details();
    T.Enter_Annual_Salary_Details();
    T.set_gen_det();
    T.HRA_Calculations();
    T.chapter6A();
    T.Generate_Tax();
    return 0;
}
