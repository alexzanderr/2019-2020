
package Useful;

public class InstantiationException extends Exception {

    private String message;

    public InstantiationException() {
        this.message = "Information about the error is unknown.";
    }

    public InstantiationException(final String message) {
        this.message = message;
    }

    @Override
    public String toString() {
        String result = String.format("<The error is '%s'>", this.message);
        return result;
    }
}
