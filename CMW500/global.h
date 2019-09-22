#ifndef GLOBAL_H
#define GLOBAL_H


class Global
{ 
public:
    static Global * getInstance();
private:
    Global();
    Global(const Global * ) = delete;
    static Global * globalInstance;

};

#endif // GLOBAL_H
