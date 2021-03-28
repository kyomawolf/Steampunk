using UnityEngine;

public class CanvasScriptGame : MonoBehaviour
{

    public int menuMode;
    public int buildingButtonID;
    public static bool isBuildingMode;

    private void Start()
    {
        menuMode = 0;
        isBuildingMode = false;
    }

    private void MenuModeHandler()
    {
        switch (menuMode)
        {
            case 0:
                break;
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
        }
    }

    private void BuildingButtonBuilding()
    {
        switch (menuMode)
        {
            case 0:
                switch (buildingButtonID)
                {
                    case 0:
                        break;
                    case 1:
                        break;
                    case 2:
                        break;
                    case 3:
                        break;
                    case 4:
                        break;
                    case 5:
                        break;
                    case 6:
                        break;
                    case 7:
                        break;
                }
                break;
            case 1:
                switch (buildingButtonID)
                {
                    case 0:
                        break;
                    case 1:
                        break;
                    case 2:
                        break;
                    case 3:
                        break;
                    case 4:
                        break;
                    case 5:
                        break;
                    case 6:
                        break;
                    case 7:
                        break;
                }
                break;
            case 2:
                switch (buildingButtonID)
                {
                    case 0:
                        break;
                    case 1:
                        break;
                    case 2:
                        break;
                    case 3:
                        break;
                    case 4:
                        break;
                    case 5:
                        break;
                    case 6:
                        break;
                    case 7:
                        break;
                }
                break;
            case 3:
                switch (buildingButtonID)
                {
                    case 0:
                        break;
                    case 1:
                        break;
                    case 2:
                        break;
                    case 3:
                        break;
                    case 4:
                        break;
                    case 5:
                        break;
                    case 6:
                        break;
                    case 7:
                        break;
                }
                break;
        }
    }

    public void MenuButton (int onClick)
    {
        if (menuMode == onClick)
        {
            return;
        }
        menuMode = onClick;
        MenuModeHandler();
    }

    public void BuildingButton (int onClick)
    {
        if (isBuildingMode)
        {
            isBuildingMode = false;
            return;
        }
        else
        {
            isBuildingMode = true;
            buildingButtonID = onClick;
            BuildingTilemap.buildCount = buildingButtonID;
            //BuildingButtonBuilding();
        }
        
    }
    
}
