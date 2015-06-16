#pragma once
#include "Grammar.h"
#include "TypeDefine.h"
#include "First.h"
#include "Follow.h"
#include <deque>
#include <vector>
using namespace std;
class SLR_Table
{
public:
  typedef deque<map<string, Action > >      TypeAction;
  typedef deque<map<string, int   >  >      TypeGoto;
public:
  SLR_Table(const Grammar&      m_grammar,const First& first,const Follow& follow);
  ~SLR_Table(void);
   /* [����SLR ������]*/
  bool      gen_table(string& error_str);
   /* [����GOTOֵ] */
  bool      get_goto(int ,const Index& index, int& );
   /* [���ض�����] */
  bool      get_action(int cur,const Index& index, Action& out_action)const;
   /* [���ö�����] */
  bool      add_to_action_s(int cur,const Index& index,int nxt);
  bool      add_to_action_r(int index_of_itemc,int index_of_item,const Index& index);
  bool      add_to_action_a(int cur);
   /* [����goto��] */
  void      add_to_goto(int index_of_itemc,const Index& index, int nxt);
   /* [�ַ�����ʾ] */
  string      ToString();
private:
  const Grammar&      m_grammar;
  const First&      m_first;
  const Follow&      m_follow;
  TypeAction          m_action_table;
  TypeGoto            m_goto_table;
};
