class Cashier {
public:
    double disc;
    int num;
    unordered_map<int,int> m;
    int cnt=0;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        num=n;
        disc=discount/100.0;
        for(int i=0;i<products.size();i++)
            m[products[i]]=prices[i];
        cout<<n<<endl;
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        double bill=0.0;
        cnt++;
        for(int i=0;i<product.size();i++){
            bill+=(m[product[i]]*amount[i]);
            cout<<bill<<endl;
        }
        cout<<endl;
        if(cnt%num==0)
            return (1-disc)*bill;
        return bill;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */
