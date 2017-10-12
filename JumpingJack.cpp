int maxStep(int n, int k) {
    cout<<"\nNumber of steps:"<<n;
    cout<<"\nDon't Land on:"<<k;
    int maxSteps=0;
    int step=0;
    int nstep=0;
    bool flag=true;

    for(int i=1;i<n+1;i++){
        if(nstep+i!=k)
            nstep=nstep+i;
    }
    cout<<"\nNStep"<<nstep;

    for(int i=1;i<n+1;i++){
        if(k==1 && (i==1) )
        {
            cout<<"\nSkipping";
        }
        else {
            if(k!=1 && step+(i+1)!=k && flag){
                cout<<"\nSkipped first step at i:"<<i<<" and step shoudl be 0:"<<step;
                flag=false;
            }
            else{ //02 02  skip->
                cout<<"\n1Adding at i:"<<i<<" to "<<step<<" to get:"<<step+i;
                step=step+i;
                flag=false;
            }
        }
    }
    return (step>nstep?step:nstep);
}
