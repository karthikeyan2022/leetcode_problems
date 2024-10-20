#include "buildtree.h"

using namespace std;

bool checkIfSlotAvailable(TreeNode* parent, TreeNode* node, int curr_level, int level, TreeNode* add_node)
{
    // if level is reached and can be added return true;
    if(curr_level == level)
    {
        if(node != 0)
        {
            return false;
        }
        else
        {
            if(parent->left == 0)
            {
                parent->left = add_node;
            }
            else // right is empty
            {
                parent->right = add_node;
            }
            return true;
        }
    }

    if(node == 0)
    {
        return false;
    }

    if(node->val == NULL_NUM)
    {
        return false;
    }


    bool ret = false;

    
    ret = checkIfSlotAvailable(node, node->left, curr_level+1, level, add_node);

    if(ret == true)
        return ret;

     
    ret = checkIfSlotAvailable(node, node->right, curr_level+1, level, add_node);

    if(ret == true)
        return ret;

    return ret;
}

bool checkSlotAtTreeLevel(int level, TreeNode* add_node, TreeNode** root)
{
    bool result = false;
    // First time add
    if(*root == 0) // level should be 0
    {
        *root = add_node;
        return true;
    }

    // level > 0
    if(level > 0)
    {
        result = checkIfSlotAvailable(0, *root, 0, level, add_node);
    }

    return result;

}

bool parseVector(string line, std::vector<int>& nums)
{
    int c = 0;
     
    if(line[0] == '\0' || line[0] != '[')
    {
        std::cout << "Check input txt file!!!" << std::endl;
        return 0;
    }

    int startIdx = 0;
    int endIdx = 0;
    // remove [ ]
    line.erase(line.begin(), line.begin()+1);
    line.erase(line.end()-1, line.end());
    vector<string> strings;
    
    for(int i = 0; i <= line.size(); i++)
    {
        if(line[i] == ',' || i == line.size())
        {
            endIdx = i;
            string temp;
            temp.append(line, startIdx, endIdx - startIdx);
            strings.push_back(temp);
            startIdx = endIdx + 1;
        }
    }

    for(int i = 0; i < strings.size(); i++)
    {
        if(strings[i] == "null")
        {
            nums.push_back(NULL_NUM);
        }
        else
        {
            nums.push_back(atoi(strings[i].c_str()));
        }

    }

    return 1;
}

void removeNullNodes(TreeNode* parent, TreeNode* node, bool isLeft)
{
    if(node == 0)
    {
        return;
    }

    if(node->val == NULL_NUM)
    {
        if(parent != 0)
        {
            if(isLeft)
                parent->left = 0;
            else
                parent->right = 0;
        }
        
        delete node;
        return;
    }

    removeNullNodes(node, node->left, true);
    removeNullNodes(node, node->right, false);

}
TreeNode* convertLineToTree(string line)
{
    vector<int> nums;
    parseVector(line, nums);

    TreeNode* root = 0;
    int level = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        // create a node
        TreeNode* node = new TreeNode(nums[i]);
        if(i == 0)
        {
            checkSlotAtTreeLevel(level, node, &root);
            level++;
            continue;
        }

        while(checkSlotAtTreeLevel(level, node, &root) == false)
        {
            level++;
        }
    }

    // remove the null nodes 
    removeNullNodes(0, root, true);
    return root;

}

string GetFileName(char* pcFileName)
{
    string sFileName = pcFileName;
    sFileName.erase(sFileName.end()-3, sFileName.end());

    sFileName.push_back('t');
    sFileName.push_back('x');
    sFileName.push_back('t');
    return sFileName;
}

bool isTxtFilePresent(string sFileName)
{
    ifstream inFilestream;
    inFilestream.open(sFileName);

    if(inFilestream.fail())
    {
        cout << "Txt file for this problem is not present." << endl;
        cout << "creating an empty txt file and closing the program..." << endl;
        inFilestream.close();

        ofstream createFilestream;
        createFilestream.open(sFileName);
        createFilestream.close();
        return false;
    }
   
    return true;
}
TreeNode* buildTreeFromFile(char* pcFileName)
{
    TreeNode* root = 0;

    string sFileName = GetFileName(pcFileName);

    cout << "File name : " << sFileName << endl;

    // 1. check if it is already present

    

    if(isTxtFilePresent(sFileName) == false)
    {
        return 0;
    }

    string line;
    ifstream inFilestream;
    inFilestream.open(sFileName);
    
    if (inFilestream.is_open())
    {
        // currenlty exit at first line
        while (getline(inFilestream, line) )
        {
            cout << line << '\n';
            root = convertLineToTree(line);
        }
        
        cout << "parsing completed." << endl;
    }
    else
    {
        // could not create file
        cout << "Unable to open file" << endl;
        return 0;
    }

    return root;
}