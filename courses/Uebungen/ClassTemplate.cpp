template <typename T, typename U>

class Pair{
    private:
        T typ1;
        U typ2;
    public:
        Pair(T typ1, U typ2): typ1(typ1), typ2(typ2){};
        
        T getTyp1() const{
            return this.typ1;
        }
        U getTyp2() const{
            return this.typ2;
        }

        void setTyp1(T typ1){
            this.typ1 = typ1;
        }
        void setTyp2(U typ2){
            this.typ2 = typ2;
        }
};